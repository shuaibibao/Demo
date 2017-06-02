package dao;

import material.Goods;
import util.DButil;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class GoodDao {
	/*
	 * ��ѯ��Ʒ�� �������Ʋ��� ���߲�������Ʒ
	 */
	public List<Goods> find(String name, String city) {
		Connection conn = DButil.getConn();
		PreparedStatement pst = null;
		ResultSet rs = null;
		List<Goods> goods = new ArrayList<Goods>();
		String sql = "select * from items where 1=1";// ��ѯȫ����
		if (name != null) {
			sql = sql + " and name='" + name + "'";// ����name
		}
		if (city != null) {
			sql = sql + " and city='" + city + "'";// ����city
		}
		try {
			pst = conn.prepareStatement(sql);
			rs = pst.executeQuery();

			while (rs.next()) {
				Goods good = new Goods(rs.getInt("id"), rs.getString("city"), rs.getString("name"), rs.getInt("price"),
						rs.getInt("number"), rs.getString("picture"));
				goods.add(good);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return goods;// ����һ��goods��list
	}

	public Goods findById(Integer id) {
		/*
		 * ��ѯ��Ʒ�� ����id ���߲�������Ʒ
		 */
		Connection conn = DButil.getConn();
		PreparedStatement pst = null;
		ResultSet rs = null;
		Goods good = null;
		String sql = "select * from items where id=?";
		System.out.println(sql);
		try {
			pst = conn.prepareStatement(sql);
			pst.setInt(1, id);// ���ʺ�ռλ�����
			rs = pst.executeQuery();

			if (rs.next()) {
				good = new Goods(rs.getInt("id"), rs.getString("city"), rs.getString("name"), rs.getInt("price"),
						rs.getInt("number"), rs.getString("picture"));
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return good;// ����һ��������Ʒ
	}

	// ��ȡ��������ǰ������Ʒ��Ϣ
	public List<Goods> getGoodList(String list) {
		// System.out.println("list:"+list);
		List<Goods> goodlist = new ArrayList<Goods>();
		int iCount = 5; // ÿ�η���ǰ������¼
		if (list != null && list.length() > 0) {
			String[] arr = list.split("-");// list����洢�����������Ʒ��id�ַ�����'-'��ƴ��
			// System.out.println("arr.length="+arr.length);
			// �����Ʒ��¼���ڵ���5��
			if (arr.length >= 5) {
				for (int i = arr.length - 1; i >= arr.length - iCount; i--) {
					goodlist.add(findById(Integer.parseInt(arr[i])));
				}
			} else {
				for (int i = arr.length - 1; i >= 0; i--) {
					goodlist.add(findById(Integer.parseInt(arr[i])));
				}
			}
			return goodlist;
		} else {
			return null;
		}
	}
}