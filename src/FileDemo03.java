import java.io.File;
import java.io.IOException;

public class FileDemo03 {

	public static void main(String[] args) {
		String path="f:"+File.separator+"test.txt";//不能在系统默认盘中创建文件
		File f=new File(path);
		try{
			f.createNewFile();
		}catch(IOException e){
			e.printStackTrace();
		}
System.out.println("OK");
	}

}
