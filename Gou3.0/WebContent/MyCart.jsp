<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
   <%@ page import="java.util.*"  %>
   <%@ page import="dao.GoodDao,material.Goods,material.Cart" %>
<!-- 此页面是显示用户的购物车 -->
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>用户购物车</title>
</head>
<body>
<a href="index.jsp"><img src="image2/360shop.png"/></a>
当前用户：
 <%
 String name = (String) request.getSession().getAttribute("name");
 %><%=name %>
 <br><a href="Login.jsp">登录</a>
 <a href="Register.jsp">注册</a>
<center>
<hr>
<ul style="color:blue;">
<%
		Cart cart=null;
		cart=(Cart)request.getSession().getAttribute("cart");
		if(cart==null){
			out.println("<h1>对不起，您还没有购买任何商品</h1><br>");
			}else{
%>				<h3>您购买的商品有：</h3>
<%		
		HashMap<Goods,Integer> item=cart.getGoods();
		Iterator iter = item.entrySet().iterator();
		while(iter.hasNext()){
			Map.Entry<Goods,Integer> entry =(Map.Entry<Goods,Integer>)iter.next();
			
			//out.println("<li>"+item.getName()+"</li>");
			%>
		<br><img src="images/<%=entry.getKey().getPicture()%>" width="60" height="40" border="1">
		<p><%=entry.getKey().getName() %>
		价格：<%=entry.getKey().getPrice() %>￥
		数量：<%=entry.getValue() %>
		<a href="CartServlet?action=del&id=<%=entry.getKey().getId()%>">删除</a>
		</p>
		<% } %>
		
</ul>
<a href="OrderForm.jsp">支付</a>
<% }%>
<a href="index.jsp">返回继续选购</a>
</center>
</body>
</html>