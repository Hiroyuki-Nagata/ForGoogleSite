<!-- session.jsp start -->
<%
	// isNewメソッドでセッション管理されているか確認します
	if (session == null || session.isNew()) {
		// セッション管理されていなければエラーページに飛ばす
%><jsp:forward
	page="/jsp/sessiontimeout.jsp" />
<!-- session is null -->
<%
	} else {
		String id = (String) session.getAttribute("id");

		if (id == null || id.equals("")) {
%><jsp:forward
	page="/jsp/sessiontimeout.jsp" />
<!-- session id is null -->
<%
	}
	}
%>
<!-- session.jsp end -->