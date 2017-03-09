package Server;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Login extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public Login() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try{
			String name=request.getParameter("username");
			String psd=request.getParameter("password");
			response.setContentType("test/html；gb2312");
			PrintWriter out=response.getWriter();
    if(psd.length()>12||psd.length()<6)
			{
				
				out.println("<html>");
				out.println("<body>");
				out.println("error!");
				out.println("</body>");
				out.println("</html>");
				
			}
    else
			{
    	out.println("<html>");
		out.println("<body>");
		out.println("Success!<br>");
		out.println("username:"+name);
		out.println("</body>");
		out.println("</html>");
			}
		}catch(Exception e){
			e.printStackTrace();
		}	
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
