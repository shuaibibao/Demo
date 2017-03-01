import java.util.Set;
import java.util.TreeSet;

public class TreeSetDemo01 {

	public static void main(String[] args) {
       Set<String> allset=new TreeSet<String>();//是可以排序的的集合类型
       allset.add("C");
       allset.add("C");
       allset.add("C");
       allset.add("D");
       allset.add("B");
       allset.add("A");
       allset.add("E");
       System.out.println(allset);
	}

}
