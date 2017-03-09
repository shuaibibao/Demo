<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
<head>
<title>首页</title>
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
<body>
     <form action="login" method="post" onsubmit="return check_submit();">
      用户名：<input type="text" name="username" id="user_name"><br>
      密码：  &nbsp&nbsp&nbsp<input type="text" name="password" id="user_psd"><br>
   <input type="submit" value="登陆" >
</form>
<a href="zhuce.jsp">注册</a>
</body>
</html>