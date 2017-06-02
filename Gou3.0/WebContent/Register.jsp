<%@ page language="java" contentType="text/html; charset=utf-8"%>
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
<style type="text/css">
h1{font-family:宋体;color:black;}
</style>
<body  bgcolor="silver">
  <div  align="center">
        <h1>用户注册</h1>
        <hr>
        <div style="background:url(image2/123.jpg) no-repeat">
           <div align="center">
    <form action="RegisterDeal" method="post" onsubmit="return check_submit();">
    <table>
         <tr> 
         <td> 用户名：</td>  <td>  <input type="text" name="username" id="user_name"></td>
         </tr>
         <tr>
      <td>新密码：  </td><td><input type="password" name="password" id="user_psd"></td>
      </tr>
      <tr>
    <td>  确认密码：</td><td><input type="password" name="repassword" id="user_repsd"></td>
      </tr>
        <tr>
    <td>  验证码：</td><td><input type="text" name="code" size="20"></td><td><img border=0 src="code.jsp"></td>
      </tr>
   </table>
   <hr>
   <input type="submit" value="注册">
   </form>
   </div>
   </div>
     <div style="background:url(image2/1.jpg) no-repeat">
           <div align="center">
           <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
           </div>
           </div>
   </div>
</body>
</html>