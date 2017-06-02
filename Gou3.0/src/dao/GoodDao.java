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
	 * 查询商品， 根据名称产地 或者查所有商品
	 */
	public List<Goods> find(String name, String city) {
		Connection conn = DButil.getConn();
		PreparedStatement pst = null;
		ResultSet rs = null;
		List<Goods> goods = new ArrayList<Goods>();
		String sql = "select * from items where 1=1";// 查询全部，
		if (name != null) {
			sql = sql + " and name='" + name + "'";// 根据name
		}
		if (city != null) {
			sql = sql + " and city='" + city + "'";// 根据city
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
		return goods;// 返回一个goods的list
	}

	public Goods findById(Integer id) {
		/*
		 * 查询商品， 根据id 或者查所有商品
		 */
		Connection conn = DButil.getConn();
		PreparedStatement pst = null;
		ResultSet rs = null;
		Goods good = null;
		String sql = "select * from items where id=?";
		System.out.println(sql);
		try {
			pst = conn.prepareStatement(sql);
			pst.setInt(1, id);// 将问号占位符填充
			rs = pst.executeQuery();

			if (rs.next()) {
				good = new Goods(rs.getInt("id"), rs.getString("city"), rs.getString("name"), rs.getInt("price"),
						rs.getInt("number"), rs.getString("picture"));
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return good;// 返回一个单个商品
	}

	// 获取最近浏览的前五条商品信息
	public List<Goods> getGoodList(String list) {
		// System.out.println("list:"+list);
		List<Goods> goodlist = new ArrayList<Goods>();
		int iCount = 5; // 每次返回前五条记录
		if (list != null && list.length() > 0) {
			String[] arr = list.split("-");// list里面存储的是浏览过商品的id字符串用'-'来拼接
			// System.out.println("arr.length="+arr.length);
			// 如果商品记录大于等于5条
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