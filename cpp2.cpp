#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;
public:
	Person(){name="空白！";cout<<this<<" Person类的缺省样式的构造函数调用完毕"<<endl;}
	Person(string Name):name(Name)
	{
		cout<<this<<" Person类的带参构造函数调用完毕"<<endl;
	}
	~Person(){cout<<this<<" Person类的析构函数调用完毕"<<endl;}
	string GetName(){return name;}
};
class Doctor:public Person
{
private:
	string title;
public:
	Doctor(){title="医生";cout<<this<<" Doctor类的缺省样式的构造函数调用完毕"<<endl;}
	Doctor(string Name,string Title):Person(Name),title(Title)
	{
		cout<<this<<" Doctor类的带参构造函数调用完毕"<<endl;
	}
	~Doctor(){cout<<this<<" Doctor类的析构函数调用完毕"<<endl;}
	string GetTitle(){return title;}
};
class Armyman:public Person
{
private:
	string militaryRank;
public:
	Armyman(){militaryRank="上尉";cout<<this<<" Armyman类的缺省样式的构造函数调用完毕"<<endl;}
	Armyman(string Name,string MilitaryRank):Person(Name),militaryRank(MilitaryRank)
	{
		cout<<this<<" Armyman类的析构函数调用完毕"<<endl;
	}
	~Armyman(){cout<<this<<" Armyman类的构造函数调用完毕"<<endl;}
	string GetMilitaryRank(){return militaryRank;}
};
class ArmySurgeon:public Doctor,public Armyman
{
private:
public:
	ArmySurgeon(){cout<<this<<" ArmySurgeon类的缺省样式的构造函数调用完毕"<<endl;}
	ArmySurgeon(string Name1,string Title,string Name2,string MilitaryRank):Doctor(Name1,Title),Armyman(Name2,MilitaryRank)
	{
		cout<<this<<" ArmySurgeon类的析构函数调用完毕"<<endl;
	}
	~ArmySurgeon(){cout<<this<<" ArmySurgeon类的构造函数调用完毕"<<endl;}
	void show(){cout<<Doctor::GetName()<<","<<GetTitle()<<","<<Armyman::GetName()<<","<<GetMilitaryRank()<<endl;}
};
void main()
{
	cout<<"------------开始---------------"<<endl;
	ArmySurgeon as("张三","主治医生","李四","上校");
	cout<<"as:";
	as.show();
	cout<<"------------结束---------------"<<endl;
}
