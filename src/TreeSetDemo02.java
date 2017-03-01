import java.util.Set;
import java.util.TreeSet;
public class TreeSetDemo02 {//treeSet中的元素是有序存放，对于每个对象必须指定好排序规则，包含的类要实现Comparable接口

	public static void main(String[] args) {
		Set<Person> allset=new TreeSet<Person>();
		allset.add(new Person("张三",30));
		allset.add(new Person("李四",31));
		allset.add(new Person("王五",32));
		allset.add(new Person("王五",32));
		allset.add(new Person("王五",32));
		allset.add(new Person("赵六",33));
		allset.add(new Person("孙qi",33));
		System.out.println(allset);
	}
}
