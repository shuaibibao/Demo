
public  class Person implements Comparable<Person>{//指定排序规则，实现比较器
    private String name;
    private int age;
    public Person(String name,int age)
    {
    	this.name=name;
    	this.age=age;
    	
    }
	public String toString()
	{
		return "姓名："+this.name+";年龄:"+this.age;
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
	public boolean equals(Object obj){//覆写equals方法
		if(this==obj){
			return true;
		}
		if(!(obj instanceof Person)){
			return false;
		}
		Person p=(Person)obj;//进行向下转型
		if(this.name.equals(p.name)&&this.age==p.age){
			return true;
		}else{
			return false;
		}
	}
	public int hashCode(){
		return this.name.hashCode()*this.age;//覆写hashCode()方法，指定编码公式
	}
}


