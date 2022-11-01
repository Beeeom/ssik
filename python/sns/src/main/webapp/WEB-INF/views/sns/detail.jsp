<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
 <head>
  <title>계정 관리</title>
 </head>
 <body>
  <h1>계정 관리</h1>
  <p>이름 : ${ data.title } </p>
  <!--  <p>카테고리 : ${ data.category }</p>-->
  <!--  <p>가격 : <fmt:formatNumber type="number" maxFractionDigits="1" value="${data.price}" /></p>--> 
  <p>수정일 : <fmt:formatDate value="${data.insert_date}" pattern="yyyy.MM.dd HH:mm:ss" /></p>

  <p>
   <a href="/update?snsId=${snsId}">계정수정</a>
  </p>
  <form method="POST" action="/delete">
   <input type="hidden" name="snsId" value="${snsId}" />
   <input type="submit" value="계정탈퇴" />
  </form>
  <p>
   <a href="/list">내 계정으로</a>
  </p>
 </body>
</html>