package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class Dologin extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public Dologin() {
        super();
        
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		try{
			String name=request.getParameter("username");
			String psd=request.getParameter("password");
			if(name.equals("admin")&&psd.equals("123"))
			{
				//Ìø×ª
				response.sendRedirect("hello.jsp");
			
			}
			else{
				response.sendRedirect("index.jsp");
			}
		}catch(Exception e){
			e.printStackTrace();
		}	
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
