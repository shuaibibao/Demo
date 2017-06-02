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
		// 设置传参编码
		request.setCharacterEncoding("utf-8");
		// 响应的编码
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();
		HttpSession session = request.getSession();//首次会产生一个新的session对象
		/*
		 * request.getSession() 等价于 request.getSession(true)
		 * 这两个方法的作用是相同的，查找请求中是否有关联的jsessionid， 如果有则返回这个号码所对应的session对象，
		 * 如果没有则生成一个新的session对象。所以说， 通过此方法是一定可以获得一个session对象。
		 */
		if (session.getAttribute("name") == null) {
			response.sendRedirect(request.getContextPath() + "/Login.jsp");// 如果非法进入此页面，就跳转到登陆界面
		} else {
			out.println("<div style='background:url(image2/wo.jpg) no-repeat'><div align='center'><h1>" + session.getAttribute("name") + " 已登录成功！欢迎！</h1><br><br>");
			out.println("<a href='"+request.getContextPath()+"/index.jsp'>进入在线商城</a><br>");
			out.println("<a href='Logout'>注销</a>");
			out.println("<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>");
			out.println("</div></div>");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
