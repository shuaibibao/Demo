package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/User")
public class User extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public User() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// ���ô��α���
		request.setCharacterEncoding("utf-8");
		// ��Ӧ�ı���
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();
		HttpSession session = request.getSession();//�״λ����һ���µ�session����
		/*
		 * request.getSession() �ȼ��� request.getSession(true)
		 * ��������������������ͬ�ģ������������Ƿ��й�����jsessionid�� ������򷵻������������Ӧ��session����
		 * ���û��������һ���µ�session��������˵�� ͨ���˷�����һ�����Ի��һ��session����
		 */
		if (session.getAttribute("name") == null) {
			response.sendRedirect(request.getContextPath() + "/Login.jsp");// ����Ƿ������ҳ�棬����ת����½����
		} else {
			out.println("<div style='background:url(image2/wo.jpg) no-repeat'><div align='center'><h1>" + session.getAttribute("name") + " �ѵ�¼�ɹ�����ӭ��</h1><br><br>");
			out.println("<a href='"+request.getContextPath()+"/index.jsp'>���������̳�</a><br>");
			out.println("<a href='Logout'>ע��</a>");
			out.println("<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>");
			out.println("</div></div>");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
