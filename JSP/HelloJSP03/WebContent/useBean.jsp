<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<jsp:useBean id="student1" class="a.Student" scope="page"/>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<jsp.setProperty property="name" name="student1" value="홍길동"/>
<jsp.setProperty property="name" name="student1"/>
<jsp.setProperty property="age" name="student1" value="34"/>
<jsp.setProperty property="age" name="student1"/>
${student.name}
${student.age}
</body>
</html>