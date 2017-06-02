package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import util.DButil;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;

@WebServlet("/RegisterDeal")
public class RegisterDeal extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public RegisterDeal() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();
		request.setCharacterEncoding("utf-8");
		String name = request.getParameter("username");
		String password = request.getParameter("password");
		String repassword = request.getParameter("repassword");
		String code = request.getParameter("code");

		Connection conn = (Connection) DButil.getConn();
		Statement st = null;
		String randstr = (String) request.getSession().getAttribute("randstr");
		if (password.equals(repassword) && code.equals(randstr))
		{
			try {
				conn.setAutoCommit(false);// ����Ϊ�����ֶ��ύ
				st = (Statement) conn.createStatement();
				st.executeUpdate("INSERT INTO user  SET NAME='" + name + "',PASSWORD='" + password + "'");
				conn.commit();
			} catch (SQLException e) {
				e.printStackTrace();
			} finally {
				DButil.closeAll(conn, st, null);
			}
			out.println("<h1>���û� " + name + " ע��ɹ�</h1><br><a href='Login.jsp'>���ص�½...</a>");
		}
		else
			out.println("<h1>ע��ʧ����ȷ����֤���ȷ��������д��ȷ</h1><br><a href='Login.jsp'>���ص�½</a>");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
