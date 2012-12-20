<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

<!-- 以下転送処理・URLを変更しましょう！数字は転送までの時間です。 -->
<META HTTP-EQUIV="Refresh" CONTENT="10;URL=${pageContext.request.contextPath}">

<title>File not found / ネットマニア</title>

<link href="${pageContext.request.contextPath}/css/errorpage.css"
	rel="stylesheet" type="text/css" />
</head>

</head>

<body>
<div class="out">

<div class="404">セッションタイムアウト</div>

<div class="main">
セッションがタイムアウトしました<br>下記リンクよりトップページにお戻り下さい。
<div class="home"><a href="${pageContext.request.contextPath}">ホームへ戻る</a></div>
</div>

<div class="foot">
Copyright &copy; 2012 <a href="https://github.com/Hiroyuki-Nagata">https://github.com/Hiroyuki-Nagata</a>. All rights reserved.<br>
<a href="http://www.netmania.jp/" target="_blank">Templates by Netmania</a>
</div>

</div>
</body>
</html>
<!-- Copyright (C) Net Mania. All Rights Reserved. http://www.netmania.jp/ -->