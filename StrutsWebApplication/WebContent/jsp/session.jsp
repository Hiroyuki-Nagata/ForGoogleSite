<%
	// isNewメソッドでセッション管理されているか確認します。
	if (session.isNew()) {
		// セッション管理されていなければエラーページに飛ばす
%><jsp:forward
	page="${pageContext.request.contextPath}/sessionTimeout.do" />
<%
	}
%>