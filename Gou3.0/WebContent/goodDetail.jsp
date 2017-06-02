<%@ page language="java" contentType="text/html; charset=utf-8"
   import="dao.GoodDao,material.Goods" %>
<%@ page import="java.util.*" %>
<!-- 显示单个商品的详细信息
     此页面提供加入购物车和显示购物车的功能
     且能显示最近浏览的五件商品
 -->
<html>
<head>
<script>
function submitdata(){
var num1 = document.getElementById("num").value;
var num2 = document.getElementById("id").value;
window.location.href ='CartServlet?action=add&id='+num2+'&num='+num1;
}
</script>

<title>网络商城</title>
 <style type="text/css">
	   div{
	      float:left;
	      margin-left: 30px;
	      margin-right:30px;
	      margin-top: 5px;
	      margin-bottom: 5px;
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
 <%=name %>
    <hr>
    <h1>商品详情</h1>
    <center>
      <table width="750" height="60" cellpadding="0" cellspacing="0" border="0">
        <tr>
          <!-- 商品详情 -->
          <% 
             GoodDao itemDao = new GoodDao();
             Goods good = itemDao.findById(Integer.parseInt(request.getParameter("id")));   
         %>   
         <input type='hidden' id='id' value='<%=good.getId()%>' >
          <td width="70%" valign="top">
             <table>
               <tr>
                 <td rowspan="4"><img src="images/<%=good.getPicture()%>" width="200" height="160"/></td>
               </tr>
               <tr>
                 <td><B><%=good.getName() %></B></td> 
               </tr>
               <tr>
                 <td>产地：<%=good.getCity()%></td>
               </tr>
               <tr>
                 <td>价格：<%=good.getPrice() %>￥</td>
               </tr> 
               <tr>
                 <td>数量：<input name='num' type='text' vlaue='1' id='num'>个</td>
               </tr> 
               <tr>
                 <td><input type="image" src="image2/in_cart.png" onclick="return submitdata();"/></td>
                 <td><a href="CartServlet?action=show"><img src="image2/view_cart.jpg"/></a></td>
               </tr> 
               <tr><td><a href='index.jsp'><img src="image2/go_shopping.jpg"/></a>
               </td></tr>
             </table>
          </td>
            
          <% 
          String list ="";
          //从客户端获得Cookies集合
          Cookie[] cookies = request.getCookies();
          //遍历这个Cookies集合
          if(cookies!=null&&cookies.length>0)
          {
              for(Cookie c:cookies)
              {
                  if(c.getName().equals("ListViewCookie"))
                  {
                     list = c.getValue();//得到listViewCookie中的内容
                  }
              }
          }
          
          list+=request.getParameter("id")+"-";//将当前id号与历史记录拼接起来，注意是拼在最前面
          //如果浏览记录超过100条，清零.
          String[] arr = list.split("-");
          if(arr!=null&&arr.length>0)
          {
              if(arr.length>=100)
              {
                  list="";
              }
          }
          Cookie cookie = new Cookie("ListViewCookie",list);//进行覆盖，是一种键值对的形式
          response.addCookie(cookie);
          %>
          <% 
             
              //从客户端获得Cookies集合 
              
              //遍历这个Cookies集合"ListViewCookie"
             
              //加上刚刚浏览的这个商品的id
              
              //如果浏览记录超过100条，清零.
              
             //写回到cookie中
                
          %>
          <!-- 浏览过的商品 -->
          <td width="30%" bgcolor="#EEE" align="center">
             <br>
             <b>您浏览过的商品</b><br>
             <!-- 循环开始 -->
             <% 
             List<Goods> goodlist =itemDao.getGoodList(list);
             if(goodlist!=null&&goodlist.size()>0 )
             {
                for(Goods i:goodlist)
                {
                     
             %>
             <div>
             <dl>
               <dt rowspan="4">
                 <a href="goodDetail.jsp?id=<%=i.getId()%>"><img src="images/<%=i.getPicture()%>" width="120" height="90" border="1"/></a>
               </dt>
               <dd class="dd_name"><%=i.getName() %></dd> 
               <dd class="dd_city">产地:<%=i.getCity() %>&nbsp;&nbsp;价格:<%=i.getPrice() %> ￥ </dd> 
             </dl>
             </div>
             <% 
                }
             }   
             %>
             <!-- 循环结束 -->
          </td>
        </tr>
      </table>
    </center>

</body>
</html>