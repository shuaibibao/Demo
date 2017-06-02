package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.mysql.jdbc.Statement;

//此类是得到数据库操作的连接，并且定义了得到连接和释放资源的方法
public class DButil {
	// 链接数据库
	// 使用静态方法的原因，可以直接通过"类名.方法"的形式进行调用，不需要进行重复创建对象，节省内存
	public static Connection getConn() {
		java.sql.Connection conn = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String url = "jdbc:mysql://localhost:3306/mldn?useUnicode=true&characterEncoding=utf-8";
			String username = "root";
			String password = "root";
			conn = DriverManager.getConnection(url, username, password);// 获得连接
		} catch (Exception e) {
			e.printStackTrace();
		}
		return conn;// 返回连接
	}

	/**
	 * 关闭所有资源 且按照一定的顺序释放资源
	 */
	public static void closeAll(Connection con, PreparedStatement pst, ResultSet rs) {
		if (rs != null) {
			try {
				rs.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (pst != null) {
			try {
				pst.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (con != null) {
			try {
				con.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}

	public static void closeAll(Connection con, Statement pst, ResultSet rs) {
		if (rs != null) {
			try {
				rs.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (pst != null) {
			try {
				pst.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (con != null) {
			try {
				con.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
}
