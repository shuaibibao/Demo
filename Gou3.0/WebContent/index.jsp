<%@ page language="java" contentType="text/html; charset=utf-8"
  import="servlet.*,dao.GoodDao,servlet.LoginDeal,material.Goods,java.util.*" %>
  <%@ page import="java.util.*" %>
<!-- 此页面用来展示在线商城的所有商品 -->
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>商品目录</title>
<style type="text/css">
	   div{
	      float:left;
	      margin: 10px;
	   }
	   div dd{
	      margin:0px;
	      font-size:10pt;
	   }
	   div dd.dd_name
	   {
	      color:blue;
	   }
	   div dd.dd_city
	   {
	      color:#000;
	   }
	</style>
</head>
<body>
<a href="index.jsp"><img src="image2/360shop.png"/></a>
 <%
 String name = (String) request.getSession().getAttribute("name");
 %>
 <br>
 <%if(name!=null)
 	{
	 out.println(name);
 	 out.println("<a href='MyCart.jsp'>用户中心</a>");}
 	else{
 	%>
 <a href="Login.jsp">登录</a>
 <a href="Register.jsp">注册</a>

 <%} 
 %> 
    <hr>
  <h1>商品展示</h1>
    <center>
    <table width="750" height="60" cellpadding="0" cellspacing="0" border="0">
      <tr>
        <td>
          
          <!-- 商品循环开始 -->
           <% 
           GoodDao gd = new GoodDao();
           List<Goods> list=gd.find(null,null);
           if(list!=null && list.size()>0){
        	   for(Goods good:list){       
           %>   
          <div>
          
             <dl>
               <dt>
                 <a href="goodDetail.jsp?id=<%=good.getId()%>"><img src="images/<%=good.getPicture() %>" width="120" height="90" border="1"/></a>
               </dt>
               <dd class="dd_name"><%=good.getName() %></dd> 
               <dd class="dd_city">产地:<%=good.getCity() %>&nbsp;&nbsp;价格:<%=good.getPrice() %>￥ </dd> 
             </dl>
          </div>
          <!-- 商品循环结束 -->
        
          <%
        	   }
           }
          %>
        </td>
      </tr>
    </table>
    </center>
    
</body>
</html>