#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;
public:
	Person(){name="�հף�";cout<<this<<" Person���ȱʡ��ʽ�Ĺ��캯���������"<<endl;}
	Person(string Name):name(Name)
	{
		cout<<this<<" Person��Ĵ��ι��캯���������"<<endl;
	}
	~Person(){cout<<this<<" Person������������������"<<endl;}
	string GetName(){return name;}
};
class Doctor:public Person
{
private:
	string title;
public:
	Doctor(){title="ҽ��";cout<<this<<" Doctor���ȱʡ��ʽ�Ĺ��캯���������"<<endl;}
	Doctor(string Name,string Title):Person(Name),title(Title)
	{
		cout<<this<<" Doctor��Ĵ��ι��캯���������"<<endl;
	}
	~Doctor(){cout<<this<<" Doctor������������������"<<endl;}
	string GetTitle(){return title;}
};
class Armyman:public Person
{
private:
	string militaryRank;
public:
	Armyman(){militaryRank="��ξ";cout<<this<<" Armyman���ȱʡ��ʽ�Ĺ��캯���������"<<endl;}
	Armyman(string Name,string MilitaryRank):Person(Name),militaryRank(MilitaryRank)
	{
		cout<<this<<" Armyman������������������"<<endl;
	}
	~Armyman(){cout<<this<<" Armyman��Ĺ��캯���������"<<endl;}
	string GetMilitaryRank(){return militaryRank;}
};
class ArmySurgeon:public Doctor,public Armyman
{
private:
public:
	ArmySurgeon(){cout<<this<<" ArmySurgeon���ȱʡ��ʽ�Ĺ��캯���������"<<endl;}
	ArmySurgeon(string Name1,string Title,string Name2,string MilitaryRank):Doctor(Name1,Title),Armyman(Name2,MilitaryRank)
	{
		cout<<this<<" ArmySurgeon������������������"<<endl;
	}
	~ArmySurgeon(){cout<<this<<" ArmySurgeon��Ĺ��캯���������"<<endl;}
	void show(){cout<<Doctor::GetName()<<","<<GetTitle()<<","<<Armyman::GetName()<<","<<GetMilitaryRank()<<endl;}
};
void main()
{
	cout<<"------------��ʼ---------------"<<endl;
	ArmySurgeon as("����","����ҽ��","����","��У");
	cout<<"as:";
	as.show();
	cout<<"------------����---------------"<<endl;
}
