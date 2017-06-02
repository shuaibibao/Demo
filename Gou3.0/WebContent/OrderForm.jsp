<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" import="material.Cart"%>
<!-- 此页面用来提交顶订单
 -->
<html>
<head>
<title>Insert title here</title>
</head>
<body>
          <!-- 商品详情
		          订单编号、用户、购买商品id，
		          联系号码、姓名、地址，订单日期 发货方式 
		  -->
	
	   <% Cart cart=(Cart)request.getSession().getAttribute("cart"); 
	       double price=cart.getTotalPrice();
	   %>
	      <div style="background:url(image2/k.jpg) no-repeat">
           <div align="center">
           <h1>共计金额：<%=price%></h1>
                  <form action="Pay" method="post">
            <table >
        	<tr><td>姓名:</td><td><input type="text" name="Name"></td>
        	</tr>
        	<tr><td>收货地址:</td><td><input type="text" name="Address"></td>
        	</tr>
        	<tr><td>联系号码:</td><td><input type="text" name="Tel"></td>
        	</tr>
        	<tr><td><input type="submit" value="提交订单"></td>
        	</tr>   
        	
        	
 </table>
 </form> 
 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>  
 </div>
     </div>        
</body>
</html>