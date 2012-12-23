package jp.gr.java_conf.nagata;

import java.io.File;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;

import org.apache.log4j.Logger;

public class InitServlet extends HttpServlet {

	private static Logger logger = Logger.getLogger(InitServlet.class);
	
	public void init() throws ServletException {
		/* 初期化処理 */
		logger.info("初期化処理中...");
		
		PropUtil prop = new PropUtil("db.properties");
		String dbFilePath = prop.getProperty("db.filepath") + File.separator + prop.getProperty("db.filename");
		File dbFile = new File(dbFilePath);
		
		if (!dbFile.exists()) {
			// DBファイルが存在しない場合は認証用DBを作る
			try {
				logger.info("DataBase File Path :" + dbFilePath);
				initDB(dbFilePath);
			} catch (ClassNotFoundException e) {
				logger.error("DBファイルの初期化に失敗しました");
			}
		} else {
			logger.info("DataBase File is exist :" + dbFilePath);
		}
	}
	
	/**
	 * システム初回起動時にデータベースファイルを初期化する
	 * 
	 * @param dbFilePath データベースファイルのパス
	 * @throws ClassNotFoundException
	 */
	private void initDB(final String dbFilePath) throws ClassNotFoundException {
		logger.info("認証用のDBを構築します");
		
		Class.forName("org.sqlite.JDBC");
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        
        try {
        	
        	// SQLiteにつなげに行く
        	conn = DriverManager.getConnection("jdbc:sqlite:" + dbFilePath);
        	stmt = conn.createStatement();
        	
        	// ID, Password, session, sessionIDをカラムに持つデータベースを作成する
        	// SQLiteにはBoolean型が無いので True=1、False=0 とするのが一般的なようだ
        	stmt.execute( "CREATE TABLE IF NOT EXISTS AUTH_TABLE( id TEXT, password TEXT, sessionIs INTEGER, sessionid TEXT )" );
        	
        	// とりあえずIDを準備する
        	stmt.execute( "insert into AUTH_TABLE values ( 'tiger', 'germany', 0, '' )" );
        	stmt.execute( "insert into AUTH_TABLE values ( 'sharman', 'usa', 0, '' )" );
        	stmt.execute( "insert into AUTH_TABLE values ( 'churchill', 'uk', 0, '' )" );
        	stmt.execute( "insert into AUTH_TABLE values ( 'foo', 'bar', 0, '' )" );
        	
        	// SELECTして値を見てみる
        	rs = stmt.executeQuery( "select * from AUTH_TABLE" );
        	while( rs.next() ) {
                logger.info( "ID       :" + rs.getString( 1 ) );
                logger.info( "Pass     :" + rs.getInt( 2 ) );
                logger.info( "sessionIs:" + rs.getInt( 3 ) );
                logger.info( "sessionId:" + rs.getInt( 4 ) );
            }
        	
        } catch (SQLException e) {
        	logger.error("DBファイルの初期化に失敗しました");
        } finally {
        	DBCloseHelper.connClose(conn);
        	DBCloseHelper.stmtClose(stmt);
        	DBCloseHelper.rsClose(rs);
        }
	}
}
