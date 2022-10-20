<%@page import="java.util.ArrayList"%>
<%@page import="com.javalec.daodto.MemberDTO"%>
<%@page import="com.javalec.daodto.MemberDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
request.setCharacterEncoding("utf-8");
MemberDAO memberDAO = new MemberDAO();
MemberDTO m = new MemberDTO();
ArrayList<MemberDTO> list = memberDAO.memberSelect();

out.println(m.getId()+" 입력한 아이디");
out.println(list.get(0).getId()+"찾는 패스워");
for(int i =0; i<list.size(); i++){
	if((list.get(i).getId()).equals(m.getId())) {
	out.println("이름:"+ list.get(i).getName()+ "<br>");
	out.println("아이뒤:"+ list.get(i).getId()+ "<br>");
	out.println("성별:"+ list.get(i).getGender()+ "<br>");
	out.println("암호화비번:"+ list.get(i).getPw()+ "<br>");
	}
}
%>
<br /><br />
<form action="ResetPass" name="myForm" method="post">
	<label for="pw">PW:</label>
	<input type="password" id="pw" name="pw" /><br />
	<input type="submit" value="비밀번호 재설정" />
</form>
</body>
</html>