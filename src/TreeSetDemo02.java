import java.util.Set;
import java.util.TreeSet;
public class TreeSetDemo02 {//treeSet�е�Ԫ���������ţ�����ÿ���������ָ����������򣬰�������Ҫʵ��Comparable�ӿ�

	public static void main(String[] args) {
		Set<Person> allset=new TreeSet<Person>();
		allset.add(new Person("����",30));
		allset.add(new Person("����",31));
		allset.add(new Person("����",32));
		allset.add(new Person("����",32));
		allset.add(new Person("����",32));
		allset.add(new Person("����",33));
		allset.add(new Person("��qi",33));
		System.out.println(allset);
	}
}
