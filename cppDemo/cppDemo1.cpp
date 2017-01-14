#include<iostream>
#include<cmath>
using namespace std;
class Point
{
public:
	Point(int ,int );
	~Point();
	Point(Point &P);
	int getX();
	int getY();
private:
	int x,y;
};
Point::Point(int a,int b){x=a;y=b;cout<<"point���ι��캯���������"<<x<<ends<<y<<endl;}
int Point::getX(){return x;}
int Point::getY(){return y;}
Point::Point(Point &p){x=p.x;y=p.y;cout<<"point�������캯���������"<<x<<ends<<y<<endl;}
Point::~Point(){cout<<"��("<<x<<","<<y<<")"<<"point���������������"<<x<<ends<<y<<endl;}
class Line
{
private:
	Point p1,p2;
	double dist;
public:
    Line(Point p1,Point p2);//����๹�캯��
	Line(Line &L);//����࿽�����캯��
	~Line(){cout<<"Line������������"<<endl;}
	double getDist(){return dist;}
};
Line::Line(Point P1,Point P2):p1(P1),p2(P2)
{
	cout<<"Line���캯������"<<endl;
	double dx=double(p1.getX()-p2.getX());
	double dy=double(p1.getY()-p2.getY());
	dist=sqrt(dx*dx+dy*dy);
}
Line::Line(Line &L):p1(L.p1),p2(L.p2)
{cout<<"Line�������캯��������\n";dist=L.dist;}
int main()
{
	Point myp1(1,1),myp2(4,5);
	Line myL(myp1,myp2);
	cout<<"the distance is:"<<myL.getDist()<<endl;
	Line youL(myL);
		cout<<"the distance is:"<<youL.getDist()<<endl;
	return 1;
}
