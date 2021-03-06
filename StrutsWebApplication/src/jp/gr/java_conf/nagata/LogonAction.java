package jp.gr.java_conf.nagata;

import java.io.IOException;
import java.util.UUID;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.Action;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.action.DynaActionForm;

/**
 * @author Hiroyuki Nagata
 * 2012/12/23 新規作成
 * 
 * logon.jspから入力されたIDとパスワードを検証するアクション
 */
public class LogonAction extends Action {
	
	/** ログインスタンス */
	private static Logger logger = Logger.getLogger(LogonAction.class);
	
	public ActionForward execute(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {

		// DynaFormからメッセージを取得
		DynaActionForm df = (DynaActionForm) form;
		String id = (String) df.get("id");
		String password = (String) df.get("password");
		logger.info("id=" + id + " password=" + password);

		// データベースにアクセスして、IDとパスワードが合致するかチェックする
		boolean authIsOK = false;
		
		try {
			authIsOK = DBAccessor.checkAuthentification(id, password);
		} catch (ClassNotFoundException e) {
			String message = "データベースの読み込み処理に失敗しました";
			logger.error(message, e);
		}
		
		// IDとパスワードのチェック
		if (authIsOK) {
			logger.info("認証成功");
			
			// セッションを開始します
			HttpSession session = request.getSession(true);
			// セッションに情報を設定します
			session.setAttribute("id", id);
			// セッションに独自のUUIDを付加します
			UUID uuid = UUID.randomUUID();
            String uuidStr = uuid.toString();
            session.setAttribute("uuid", uuid);
			
			return mapping.findForward("topmenu");
		} else {
			return mapping.findForward("error");
		}

	}
}
