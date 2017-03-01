import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Yard extends Frame {
	
	PaintThread  paintThread=new PaintThread();
	private boolean gameOver=false;
	

	public static final int ROWS=30;
	public static final int COLS=30;
	public static final int BLOCK_SIZE=15;
	private Font fontGameOver=new Font("宋体",Font.BOLD,50);
	private int score=0;
	Snake s=new Snake(this);
	Egg e=new Egg();
	Image offScreenImage=null;
	
	public void launch(){
	    this.setLocation(200,200);
	    this.setSize(COLS*BLOCK_SIZE,ROWS*BLOCK_SIZE);
	    this.addWindowListener(new WindowAdapter(){
	    	public void windowClosing(WindowEvent e){
	    		System.exit(0);
	    	}
	    });
	    this.setVisible(true);
	    this.addKeyListener(new KeyMonitor());
	    new Thread(paintThread).start();
	    
	}
	
	
	public static void main(String[] args) {
             new Yard().launch();

	}
    public void stop(){
    	gameOver=true;
    }
    public void paint(Graphics g){
    	Color c=g.getColor();
    	g.fillRect(0, 0, COLS*BLOCK_SIZE, ROWS*BLOCK_SIZE);
    	g.setColor(Color.darkGray);
    	//画出横线
    	for(int i=1;i<ROWS;i++)
    		g.drawLine(0, BLOCK_SIZE*i, BLOCK_SIZE*COLS, BLOCK_SIZE*i);
    	for(int i=1;i<COLS;i++)
    		g.drawLine(BLOCK_SIZE*i,0,BLOCK_SIZE*i, BLOCK_SIZE*ROWS);
    	g.setColor(Color.YELLOW);
    	g.drawString("score", 10, 60);
    	if(gameOver){
    		g.setFont(fontGameOver);
    		g.drawString("游戏结束", 120, 180);
    		paintThread.pause();
    	}
    		g.setColor(c);
    		s.eat(e);
    		e.draw(g);
    		s.draw(g);
    	}
       public void update(Graphics g){
    	   if(offScreenImage==null){
    		   offScreenImage=this.createImage(COLS*BLOCK_SIZE,ROWS*BLOCK_SIZE);
    	   }
    	   Graphics gOff=offScreenImage.getGraphics();
    	   g.drawImage(offScreenImage, 0, 0, null);
    	  
    }
    private class PaintThread implements Runnable{
    	private boolean running=true;
    	private boolean pause=false;
    	public void run(){
    		while(running){
    			if(pause)continue;
    			else repaint();
    			try{
    				Thread.sleep(100);
    			}catch(InterruptedException e){
    				e.printStackTrace();
    			}
    			
    		}
    		
    	}
    	public void pause(){
    		this.pause=true;
    	}
    	public void reStart(){
    		this.pause=false;
    		s=new Snake(Yard.this);
    	    gameOver=false;
    		
    	}
    	public void gameOver(){
    		running=false;
    	}
    	
    }
    private class KeyMonitor extends KeyAdapter{
    	public void keyPressed(KeyEvent e){
    		int key=e.getKeyCode();
    		if(key==KeyEvent.VK_F2){
    			paintThread.reStart();
    		}
    		s.keyPressed(e);
    	}
    	
    	
    }
    public int getScore(){
    	return score;
    }
    public void setScore(int score){
    	this.score=score;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}
