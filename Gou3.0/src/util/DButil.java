package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.mysql.jdbc.Statement;

//�����ǵõ����ݿ���������ӣ����Ҷ����˵õ����Ӻ��ͷ���Դ�ķ���
public class DButil {
	// �������ݿ�
	// ʹ�þ�̬������ԭ�򣬿���ֱ��ͨ��"����.����"����ʽ���е��ã�����Ҫ�����ظ��������󣬽�ʡ�ڴ�
	public static Connection getConn() {
		java.sql.Connection conn = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String url = "jdbc:mysql://localhost:3306/mldn?useUnicode=true&characterEncoding=utf-8";
			String username = "root";
			String password = "root";
			conn = DriverManager.getConnection(url, username, password);// �������
		} catch (Exception e) {
			e.printStackTrace();
		}
		return conn;// ��������
	}

	/**
	 * �ر�������Դ �Ұ���һ����˳���ͷ���Դ
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
