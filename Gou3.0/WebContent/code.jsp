<%@ page language="java" 
import="java.awt.*"
import="java.awt.image.BufferedImage"
import="java.util.*"
import="javax.imageio.ImageIO"
contentType="text/html; charset=utf-8"%>
<%
    response.setHeader("Cache_Control","no-cache");//是用来实现无缓存？
    int width=60,height=30;
    BufferedImage image=new BufferedImage(width,height,BufferedImage.TYPE_INT_RGB);//设置颜色属性
    //获取画笔
    Graphics g=image.getGraphics();
    //设定背景色
    g.setColor(new Color(100,200,200));
    g.fillRect(0,0,width,height);
    Random rnd=new Random();
    int randnum=rnd.nextInt(8999)+1000;
    String randstr=String.valueOf(randnum);
    session.setAttribute("randstr", randstr);//将验证码存入session之中，以字符串形式
    //将验证码显示到图像中
    g.setColor(Color.red);
    g.setFont(new Font("",Font.PLAIN,20));
    g.drawString(randstr, 10, 22);
    for(int i=0;i<100;i++){
    	g.setColor(new Color(i+100,2*i,i/2));
    	int x=rnd.nextInt(width);
    	int y=rnd.nextInt(height);
    	g.drawOval(x,y,1,1);//drawOval()函数
    }
    //输出图像到页面
    ImageIO.write(image,"JPEG",response.getOutputStream());//要加上后面两句，不然会出错
    out.clear();
    out=pageContext.pushBody();
%>