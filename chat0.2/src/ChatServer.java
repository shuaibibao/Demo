import java.io.DataInputStream;
import java.io.IOException;
import java.net.*;
public class ChatServer {
	
	public static void main(String[] args) {
		ServerSocket ss=null;
		DataInputStream dis=null;
		boolean started=false;
		try {
			 ss=new ServerSocket(8888);
		}catch(IOException e){
			e.printStackTrace();
		}
			
		try{
			started=true;
			while(started){
				boolean bconnected=false;
				Socket s=ss.accept();
				Client c=new Client(s);
System.out.println("a clinet connected!");
            
            new Thread(c).start();
            //dis.close();
			}
		} catch (Exception e) {
			System.out.println("client closed");
		}finally{
			
			}
		}
	}

    class Client implements Runnable  {
    	private Socket s;
    	private  DataInputStream dis=null;
    	private  boolean bConnected=false;
    	public Client(Socket s){
    		this.s=s;
    		try {
				dis=new DataInputStream(s.getInputStream());
			} catch (IOException e) {
				e.printStackTrace();
			}
    	}
    	
    	public void run()
    	{
    	   try{
    		while(bConnected){
    			String str=dis.readUTF();
    			System.out.println(str);
    		 }
    		
    		}catch(IOException e)
    	   {
    			e.printStackTrace();
    	   }try{
				if(dis!=null)dis.close();
				if(s!=null)s.close();
			}catch(IOException e1){
				e1.printStackTrace();
    	}
    }

}
