package Server;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Zhu1 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
   
    public Zhu1() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try{
			String name=request.getParameter("username");
			String psd=request.getParameter("password");
			String repsd=request.getParameter("repassword");
			response.setContentType("test/html£»gb2312");
			PrintWriter out=response.getWriter();
			if(psd.equals(repsd)&&psd.length()<=12&&psd.length()>=6){
				out.println("<html>");
				out.println("<body>");
				out.println("success!<br>");
				out.println("username:"+name);
				out.println("<a href='http://localhost:8080/Login/login.jsp'>return to the loginPage</a>");
				out.println("</body>");
				out.println("</html>");
			}else{
				out.println("<html>");
				out.println("<body>");
				out.println("login failed!<br>");
				if(psd.length()>=12&&psd.length()<=6)
					out.println("password'length belong to 6~12<br>"); 
				out.println("password shuld be no difference<br>");
				out.println("");
				out.println("</body>");
				out.println("</html>");
			}	
		}
		catch(Exception e){
			e.printStackTrace();
		}
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
