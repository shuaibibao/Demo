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
		//�������ݿ�
		//��ȡ����
		//�������ݽ����ݿ�
		//��ת���ɹ�����ҳ�沢���ɶ�����Ϣ
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out=response.getWriter();
		
		Connection conn = (Connection) DButil.getConn();
		Statement mystatement=null;
		//��ȡsession
		HttpSession session=request.getSession();
		Cart cart=(Cart)session.getAttribute("cart");
		
		String Name=request.getParameter("Name");
		String Address=request.getParameter("Address");
		String Tel=request.getParameter("Tel");
		
		Integer isFinish= 0;
		String MakeTime=null;
		Date MTime = new Date();
		MakeTime=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(MTime);//���涩��������ʱ�� 
		String UserName=(String) session.getAttribute("name");//�õ������˺���
		double TotalPrice= cart.getTotalPrice();
		Random rnd=new Random();
		int randnum=0;
		/**���붩���������Ҫ������**/
		//����id���ݶ�����õ�����hushmap�õ�good&num
		try{
			//���ɶ������
			Iterator iter = cart.getGoods().entrySet().iterator();
			
			randnum=rnd.nextInt(8999)+1000;
			while(iter.hasNext()){
			Map.Entry<Goods,Integer> entry =(Map.Entry<Goods,Integer>)iter.next();
			int GoodId=entry.getKey().getId();//�������е���Ʒid��
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
		 //��ת����������ҳ��----------����һ����ȫ��Ϣ�Ķ��������
		         out.println("<div align='center'>");
		         out.println("<table width='400px' height='400px' frame='box'>");
		         out.println("<tr>");
		         out.println("<td>������"+Name+"</td>");
		         out.println("<td>�����ţ�"+randnum+"</td>");
		         out.println("</tr>");
		         out.println("<tr>");
		         out.println("<td>��ϵ�绰��"+Tel+"</td>");
		         out.println("<td>סַ��"+Address+"</td>");
		         out.println("<td>");
		         
		         Iterator iter = cart.getGoods().entrySet().iterator();
		         while(iter.hasNext()){
		 			Map.Entry<Goods,Integer> entry =(Map.Entry<Goods,Integer>)iter.next();
		 			String Goodname=entry.getKey().getName();//�������е���Ʒid��
		 			int GoodsNum=entry.getValue();
		         out.println("<tr>");
		         out.println("<td>��Ʒ����"+Goodname+"</td>");
		         out.println("<td>������"+GoodsNum+"</td>");
		         out.println("</tr>");
		         }
		         out.println("<h1>�������ڣ�"+MakeTime+"</h1>");
		         out.println("</table>");
		         out.println("<a href='Logout'>ע����½</a><br>");
		         out.println("<a href='"+request.getContextPath()+"/index.jsp'>���������̳�</a><br>");
		         out.println("</div>");
		         
		         
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
