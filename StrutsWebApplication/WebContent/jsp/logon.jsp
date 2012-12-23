<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="/tags/struts-html.tld" prefix="html"%>
<%@ taglib uri="/tags/sslext.tld" prefix="sslext" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>ログイン画面</title>

<link href="${pageContext.request.contextPath}/css/login-box.css"
	rel="stylesheet" type="text/css" />
</head>

<body>

	<div style="padding: 100px 0 0 250px;">
		<div id="login-box">

			<H2>ログイン</H2>
			フォームにユーザーIDとパスワードを入力してください <br /><br />
			<!-- HTTP/POST -->
			<sslext:form action="/logon" >
				<div id="login-box-name" style="margin-top: 20px;">ユーザーID:</div>
				<div id="login-box-field" style="margin-top: 20px;">
					<input name="id" class="form-login" title="Username" value=""
						size="30" maxlength="2048" />
				</div>
				<div id="login-box-name">パスワード:</div>
				<div id="login-box-field">
					<input name="password" type="password" class="form-login" title="Password"
						value="" size="30" maxlength="2048" />
				</div>
				<br />
				<span class="login-box-options"><input type="checkbox"
					name="1" value="1"> パスワードを記憶する <a href="#"
						style="margin-left: 30px;">パスワードをお忘れですか？</a></span>
				<br />
				<br />
				<input type="image" src="${pageContext.request.contextPath}/images/login-btn.png" width="103" height="42" style="margin-left: 90px;" name="submit">
			</sslext:form>

		</div>

	</div>
</body>
</html>