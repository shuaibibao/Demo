import java.io.File;
import java.io.IOException;

public class FileDemo03 {

	public static void main(String[] args) {
		String path="f:"+File.separator+"test.txt";//������ϵͳĬ�����д����ļ�
		File f=new File(path);
		try{
			f.createNewFile();
		}catch(IOException e){
			e.printStackTrace();
		}
System.out.println("OK");
	}

}
