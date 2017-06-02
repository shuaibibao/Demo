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
		// 连接数据库
		Connection conn = (Connection) DButil.getConn();
		Statement mystatement = null;
		ResultSet rs = null;
		try {
			// 接受用户名密码
			String name = request.getParameter("username");
			String pass = request.getParameter("password");
			mystatement = (Statement) conn.createStatement();// 创建一个statement
			rs = mystatement.executeQuery("SELECT * FROM user WHERE NAME='" + name + "'AND PASSWORD='" + pass + "'");
			if (rs.next()) {
				HttpSession session = request.getSession();
				/*
				 * 加入新功能：存储session的id号实现二次浏览
				 */
				session.setAttribute("name", name);// 将用户名存入session
				request.getRequestDispatcher("/User").forward(request, response);// 登陆成功就跳转到用户的servlet
			} else {
				response.sendRedirect(request.getContextPath() + "/Login.jsp");// 不存在的时候就跳转到注册界面
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
