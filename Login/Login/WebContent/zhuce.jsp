<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
<head>
<title>注册</title>
<script type="text/javascript">
   function check_submit(){
	   if($("user_name").value==""){alert("请填写用户名");return false;}
	   if($("user_psd").value==""){alert("请填写密码");return false;}
	   if($("user_repsd").value==""){alert("请填写密码");return false;}
	   return true;
   }
  function $(str){
	   return (document.getElementById(str));
   }
</script>
</head>
<body>
    <form action="Zhu1" method="post" onsubmit="return check_submit();">
      用户名：<input type="text" name="username" id="user_name"><br>
      新密码：  &nbsp&nbsp&nbsp<input type="text" name="password" id="user_psd"><br>
      确认密码：<input type="text" name="repassword" id="user_repsd"><br>
   <input type="submit" value="注册">
</body>
</html>