import java.awt.*;
import java.awt.event.*;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.*;

public class ChatClient extends Frame {

	TextField tfTxt = new TextField();
	Socket s=null;
	TextArea taContent = new TextArea();
    DataOutputStream dos=null;
	public void launchFrame() {
		setLocation(400, 300);
		this.setSize(300, 300);
		add(tfTxt, BorderLayout.SOUTH);
		add(taContent, BorderLayout.NORTH);
		pack();
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				disconnect();
				System.exit(0);
			}
		}
		);
		tfTxt.addActionListener(new TFListener());
		setVisible(true);
		connect();
	}
	public void connect()
	{
		try{
	    s =new Socket("127.0.0.1",8888);
	    dos=new DataOutputStream(s.getOutputStream());
System.out.println("connected");
		}catch(UnknownHostException e){
			e.printStackTrace();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	private class TFListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String str=tfTxt.getText().trim();
			taContent.setText(str);
			tfTxt.setText("");
			try {
				
			    dos.writeUTF(str);
			    dos.flush();
			    //dis.close();
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
	}
	public void disconnect()
	{
		try{
			dos.close();
			s.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new ChatClient().launchFrame();
	}
}
