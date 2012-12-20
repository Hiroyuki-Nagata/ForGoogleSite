<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ include file="session.jsp" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>トップメニュー画面</title>

<link href="${pageContext.request.contextPath}/css/button.css"
	rel="stylesheet" type="text/css" />
</head>
<STYLE type=text/css>

.ss{
	FONT-SIZE: 8pt
}
BODY {
	FONT-SIZE: 12px; COLOR: #777777; LINE-HEIGHT: 155%;
}
TD {
	FONT-SIZE: 12px; COLOR: #777777; LINE-HEIGHT: 155%; 
}

a:link {
	color: #666666;
		text-decoration: none;
}
a:visited {
	color: #888888;
	text-decoration: none;
}
a:hover {
	color: #333333;
	text-decoration: none;
}
</STYLE>

</head>

<body leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">
<table width="100%" height="25" border="0" cellpadding="0" cellspacing="0" bgcolor="#000000">
  <tr>
    <td>　</td>
  </tr>
</table>
<table width="100%" height="100" border="0" cellpadding="0" cellspacing="0" style="BORDER-BOTTOM: #cccccc 1px solid"
>
  <tr>
    
<td valign="middle"><img src="${pageContext.request.contextPath}/images/title.gif" width="168" height="33" vspace="10" hspace="20"></td>
  </tr>
</table>
<br>
<br>
<table width="100%" height="160" border="0" cellpadding="0" cellspacing="0" style="BORDER-RIGHT: #990000 170px solid;BORDER-LEFT: #990000 30px solid;BORDER-TOP: #cccccc 1px solid">
  <tr>
    <td height="138" bgcolor="#F8F8F8"><table width="90%" border="0" align="center" cellpadding="3" cellspacing="0">
					<tr>
						<td width="50%">
							<li><a href="" class="shiny-button"><strong>メニュー</strong></a></li>
							<li><a href="" class="shiny-button"><strong>リンク</strong></a></li>
							<li><a href="" class="shiny-button"><strong>BBS</strong></a></li>
							<li><a href="" class="shiny-button"><strong>100の質問(激寒)</strong></a></li>
							<li><a href="" class="shiny-button"><strong>Free Software Foundation</strong></a></li>
						</td>
						<td width="50%" valign="top"><strong>Struts
								1.2.4を使用したサンプルアプリケーション</strong><br>
							さすがにServlet/JSPの組み合わせでWEBアプリは作りたくないですよね。フレームワークを使う練習をしましょう。
							…えっ、Strutsも十分古い？そうかもねえ</td>
					</tr>
				</table>
    </td>
  </tr>
</table>
<br>
<br>
<br>
<table width="100%" border="0" cellpadding="5" cellspacing="0" style="BORDER-TOP: #cccccc 1px solid"
>
  <tr>
    <td bgcolor="#EFEFEF">Copyright Hiroyuki Nagata 2012 &copy; Struts Training. All Rights Reserved.  
    <!-- 以下削除禁止 --><a href="http://www.netmania.jp/" target="_blank">テンプレート by ネットマニア</a></td>
  </tr>
</table>
<br>

<br>
</body>
</html>
<!-- Copyright (C) Net Mania. All Rights Reserved. http://www.netmania.jp -->