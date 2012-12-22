package jp.gr.java_conf.nagata;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.apache.log4j.Logger;

public class DBCloseHelper {

	private static Logger logger = Logger.getLogger(DBCloseHelper.class);
	
	public static void connClose(Connection conn) {
		try {
			conn.close();
		} catch (SQLException e) {
			logger.error("DBのクローズ処理に失敗しました");
		}
	}
	
	public static void stmtClose(Statement stmt) {
		try {
			stmt.close();
		} catch (SQLException e) {
			logger.error("DBのクローズ処理に失敗しました");
		}
	}
	
	public static void rsClose(ResultSet rs) {
		try {
			rs.close();
		} catch (SQLException e) {
			logger.error("DBのクローズ処理に失敗しました");
		}
	}
}
