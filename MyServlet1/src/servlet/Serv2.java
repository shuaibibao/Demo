package servlet;

import java.io.IOException;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class Serv2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public Serv2() {
        System.out.println("���캯����ִ��"); 
    }
	public void init(ServletConfig config) throws ServletException {
		System.out.println("��ʼ����ִ��");
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("doget��ִ��");
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("dopost��ִ��");
	}

}
