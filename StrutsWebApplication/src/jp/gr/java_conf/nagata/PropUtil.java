package jp.gr.java_conf.nagata;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.Properties;

import org.apache.log4j.Logger;

public class PropUtil {

	private static Logger logger = Logger.getLogger(PropUtil.class);
	
	private Properties conf;
	
	public PropUtil(String filename){
		
        conf = new Properties();
        
        //Class c = this.getClass();
		//URL url = c.getResource(filename);
		InputStream is = null;
        
        try {
        	//is = c.getResourceAsStream(filename);
        	is = this.getClass().getClassLoader().getResourceAsStream(filename);
            conf.load(is);
        } catch (IOException e) {
            logger.error("Cannot open " + filename + ".");
        }
    }
	
	public String getProperty(String key) {
        if(conf.containsKey(key))
            return conf.getProperty(key);
        else {
        	logger.error("Key not found: " + key);
            return "";
        }
    }
}
