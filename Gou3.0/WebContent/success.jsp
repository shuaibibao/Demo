<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
   <%@ page import="java.util.*" import="dao.GoodDao,material.Goods,material.Cart"%>
<!-- 此页面是加入购物车成功的时候显示 -->
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Insert title here</title>
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
<img src="image2/add_cart_success.jpg" width="300" height="80">
<a href="CartServlet?action=show"><img src="image2/view_cart.jpg"/></a>
<br>
<a href="index.jsp">返回继续选购</a>
</center>
</body>
</html>