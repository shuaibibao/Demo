package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Servlet1 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public Servlet1() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");//
		PrintWriter out=response.getWriter();//Ϊ�˵õ�����ַ������
		out.println("<html>");
		out.println("<body>");
		out.println("<h3>servletѧϰ</h3>");
		Date date=new Date(1);
		out.println("<h3>��ǰʱ���ǣ�"+date+"</h3>");
		out.println("</body>");	
		out.println("</html>");
		out.close();		
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
