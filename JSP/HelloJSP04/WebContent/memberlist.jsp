<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1> DB 연결된 테이블</h1>
<table border=1>
<tr>
<th>Name</th>
<th>ID</th>
<th>폰번호</th>
<th>성별</th>
</tr>
<%Class.forName("com.mysql.cj.jdbc.Driver");
Connection conn = null;
Statement stmt = null;
ResultSet rs = null;
try{
	String jdbcDriver=
			"jdbc:mysql://localhost:3306/jspdb?"+
	"useUnicode=true&characterEncoding=utf8&"+
			"serverTimezone=UTC";
	String dbUser ="root";
	String dbPass ="1234";
	String query = "select * from member";
	conn = 
			DriverManager.getConnection(jdbcDriver,dbUser,dbPass);
	stmt = conn.createStatement();
	rs=stmt.executeQuery(query);
	while(rs.next())
	{
%>
<tr>
<th><%=rs.getString("name") %></th>
<th><%=rs.getString("id") %></th>
<th><%=rs.getString("hp")%></th>
<th><%=rs.getString("gender") %></th>
</tr>
<%}
}catch(Exception e)
{
	e.printStackTrace();
}finally{
	rs.close();
	stmt.close();
	conn.close();
}


%>
</table>
</body>
</html>