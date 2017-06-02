package servlet;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.*;
import util.DButil;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;

import material.Cart;
import material.Goods;


@WebServlet("/Pay")
public class Pay extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public Pay() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//连接数据库
		//获取数据
		//保存数据进数据库
		//跳转到成功购买页面并生成订单信息
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out=response.getWriter();
		
		Connection conn = (Connection) DButil.getConn();
		Statement mystatement=null;
		//获取session
		HttpSession session=request.getSession();
		Cart cart=(Cart)session.getAttribute("cart");
		
		String Name=request.getParameter("Name");
		String Address=request.getParameter("Address");
		String Tel=request.getParameter("Tel");
		
		Integer isFinish= 0;
		String MakeTime=null;
		Date MTime = new Date();
		MakeTime=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(MTime);//保存订单的生成时间 
		String UserName=(String) session.getAttribute("name");//得到网上账号名
		double TotalPrice= cart.getTotalPrice();
		Random rnd=new Random();
		int randnum=0;
		/**插入订单项表所需要的数据**/
		//订单id根据订单表得到，由hushmap得到good&num
		try{
			//生成订单项表
			Iterator iter = cart.getGoods().entrySet().iterator();
			
			randnum=rnd.nextInt(8999)+1000;
			while(iter.hasNext()){
			Map.Entry<Goods,Integer> entry =(Map.Entry<Goods,Integer>)iter.next();
			int GoodId=entry.getKey().getId();//订单项中的商品id号
			int GoodsNum=entry.getValue();
			mystatement=(Statement) conn.createStatement();
			mystatement.executeUpdate("INSERT INTO Dingdanxiang SET GoodId="+GoodId+",GoodNumber="+GoodsNum
					+",DingdanId="+randnum+"");
			}
			//
			mystatement=(Statement) conn.createStatement();
			mystatement.executeUpdate("INSERT INTO Dingdan  SET id="+randnum+",TotalPrice="+TotalPrice+",Address='"+Address
					+"',Tel='"+Tel+"', Name='"
					+Name+"', isFinish="+isFinish+
					",MakeTime='"+MakeTime+"',UserName='"+UserName+"'" );
		}catch (SQLException e) {
			e.printStackTrace();
		}
	      finally{
	    	  DButil.closeAll(conn, mystatement, null);
	      }
		 //跳转到订单详情页面----------生成一个完全信息的订单详情表
		         out.println("<div align='center'>");
		         out.println("<table width='400px' height='400px' frame='box'>");
		         out.println("<tr>");
		         out.println("<td>姓名："+Name+"</td>");
		         out.println("<td>订单号："+randnum+"</td>");
		         out.println("</tr>");
		         out.println("<tr>");
		         out.println("<td>联系电话："+Tel+"</td>");
		         out.println("<td>住址："+Address+"</td>");
		         out.println("<td>");
		         
		         Iterator iter = cart.getGoods().entrySet().iterator();
		         while(iter.hasNext()){
		 			Map.Entry<Goods,Integer> entry =(Map.Entry<Goods,Integer>)iter.next();
		 			String Goodname=entry.getKey().getName();//订单项中的商品id号
		 			int GoodsNum=entry.getValue();
		         out.println("<tr>");
		         out.println("<td>商品名："+Goodname+"</td>");
		         out.println("<td>数量："+GoodsNum+"</td>");
		         out.println("</tr>");
		         }
		         out.println("<h1>订单日期："+MakeTime+"</h1>");
		         out.println("</table>");
		         out.println("<a href='Logout'>注销登陆</a><br>");
		         out.println("<a href='"+request.getContextPath()+"/index.jsp'>进入在线商城</a><br>");
		         out.println("</div>");
		         
		         
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
