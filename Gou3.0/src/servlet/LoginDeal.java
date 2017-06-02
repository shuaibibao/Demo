package servlet;

import util.DButil;
import java.io.IOException;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;

@WebServlet("/LoginDeal")
public class LoginDeal extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public LoginDeal() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		// �������ݿ�
		Connection conn = (Connection) DButil.getConn();
		Statement mystatement = null;
		ResultSet rs = null;
		try {
			// �����û�������
			String name = request.getParameter("username");
			String pass = request.getParameter("password");
			mystatement = (Statement) conn.createStatement();// ����һ��statement
			rs = mystatement.executeQuery("SELECT * FROM user WHERE NAME='" + name + "'AND PASSWORD='" + pass + "'");
			if (rs.next()) {
				HttpSession session = request.getSession();
				/*
				 * �����¹��ܣ��洢session��id��ʵ�ֶ������
				 */
				session.setAttribute("name", name);// ���û�������session
				request.getRequestDispatcher("/User").forward(request, response);// ��½�ɹ�����ת���û���servlet
			} else {
				response.sendRedirect(request.getContextPath() + "/Login.jsp");// �����ڵ�ʱ�����ת��ע�����
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			DButil.closeAll(conn, mystatement, rs);
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
