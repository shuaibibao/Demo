<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
<head>
<title>用户登录</title>
<script type="text/javascript">
  function check_submit(){
	   if($("user_name").value==""){alert("请填写用户名");return false;}
	   if($("user_psd").value==""){alert("请填写密码");return false;}
	   return true;
   }
   function $(str){
	   return (document.getElementById(str));
   }
</script>
</head>
<style type="text/css">
h1 {
	font-family: 宋体;
	color: black;
}
</style>
<body bgcolor="silver">
	<div align="center">
		<h1>用户登录</h1>
		<hr>
		<div style="background:url(image2/beijing.jpg) no-repeat">
           <div align="center">
		<form action="LoginDeal" method="post" onsubmit="check_submit();">
		
		
		  <table>
			<tr><td>用户名：</td><td><input type="text" name="username" id="user_name"></td></tr>
			<tr><td>&nbsp&nbsp&nbsp&nbsp密码：</td><td><input type="password" name="password" id="user_psd"></td></tr>
			</table>
			<input type="submit" value="登陆">
			
		</form>	
		<a href="Register.jsp">注册</a>
		
<br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
		</div>
			</div>
	</div>
     
			
</body>
</html>