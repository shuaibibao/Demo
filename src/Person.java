
public  class Person implements Comparable<Person>{//ָ���������ʵ�ֱȽ���
    private String name;
    private int age;
    public Person(String name,int age)
    {
    	this.name=name;
    	this.age=age;
    	
    }
	public String toString()
	{
		return "������"+this.name+";����:"+this.age;
	}
	public int compareTo(Person per)
	{
		if(this.age>per.age){
			return 1;
		}else if(this.age<per.age){
			return -1;
		}else {
			return this.name.compareTo(per.name);
		}
	}
	public boolean equals(Object obj){//��дequals����
		if(this==obj){
			return true;
		}
		if(!(obj instanceof Person)){
			return false;
		}
		Person p=(Person)obj;//��������ת��
		if(this.name.equals(p.name)&&this.age==p.age){
			return true;
		}else{
			return false;
		}
	}
	public int hashCode(){
		return this.name.hashCode()*this.age;//��дhashCode()������ָ�����빫ʽ
	}
}


