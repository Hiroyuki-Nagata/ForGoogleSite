package jp.gr.java_conf.nagata;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.apache.log4j.Logger;

/**
 * @author Hiroyuki Nagata
 * 2012/12/23 新規作成
 *
 * データベースにアクセスする処理全般を扱うクラス
 */
public class DBAccessor {

	/** ログインスタンス */
	private static Logger logger = Logger.getLogger(DBAccessor.class);
	
	/**
	 * @param id
	 * @param password
	 * @return ログインIDとパスワードが合致しているかどうか
	 * @throws ClassNotFoundException 
	 */
	public static boolean checkAuthentification(final String id, final String password) throws ClassNotFoundException {
		
		Class.forName("org.sqlite.JDBC");
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        String dbFilePath = InitServlet.getDbFilePath();
		
        try {
        	
        	// SQLiteにつなげに行く
        	conn = DriverManager.getConnection("jdbc:sqlite:" + dbFilePath);
        	stmt = conn.createStatement();
        	
        	/** ID, Password一致検証用SQL文 */
        	final String CHECK_AUTHENTIFICATION = "SELECT id, password "
        										 + "FROM AUTH_TABLE "
        										 + "WHERE id='" + id +"' AND password='"+ password + "'";
        	
        	// SELECTして値を見てみる
        	rs = stmt.executeQuery( CHECK_AUTHENTIFICATION );
        	
        	if (rs == null) {
        		// 返り値が無ければその場で終わり
        		return false;
        	}
        	
        	if (rs.next()) {
        		// ログにIDを出力する
        		logger.info(rs.getString("id"));
        	}
        	
        	return true;
        	
        } catch (SQLException e) {
        	logger.error("DBファイルの初期化に失敗しました");
        } finally {
        	DBCloseHelper.connClose(conn);
        	DBCloseHelper.stmtClose(stmt);
        	DBCloseHelper.rsClose(rs);
        }
        
        return false;
	}

}
