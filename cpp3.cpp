#include<iostream.h>
class Complex//definition
{
public:
		Complex(double Real=0.0,double Imag=0.0):real(Real),imag(Imag){}
	Complex(Complex &C):real(C.real),imag(C.imag){}
	void display() const;
    double real;
private:
	double imag;
	friend Complex operator + (const Complex &C1,const Complex &C2);
	friend Complex operator - (const Complex &C1,const Complex &C2);
	friend Complex& operator ++ (const Complex &C);
    friend Complex operator ++ (const Complex &C,int);
};
void Complex::display() const
{
	if(imag<0)
		cout<<real<<imag<<"i"<<" "<<this<<endl;
	else
		cout<<real<<"+"<<imag<<"i"<<" "<<this<<endl;
}
Complex operator + (const Complex &C1,const Complex &C2)//rebuild +
{
	return Complex(C1.real+C2.real,C1.imag+C2.imag);//current sytanx ob as a value
}
Complex operator - (const Complex &C1,const Complex &C2)//rebuild -
{
	return Complex(C1.real-C2.real,C1.imag-C2.imag);//current sytanx ob as a value
}
Complex& operator ++ (Complex &C)//rebuild forhead++
{
   C.real++;
	return C;
}
Complex operator ++ (Complex &C,int)//rebuild hind++
{
	Complex old=C;
	++C;
	return old;
}
int main()
{
	Complex c1(1,2),c2(3,4),c3(5,6),c4;
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	cout<<"c3=";c3.display();
	c4=c1+c2+c3;
	cout<<"c4=c1+c2+c3=";c4.display();
	c4=c1-c2;  
	cout<<"c4=c1-c2=";c4.display();
	cout<<"++++++c4=";(++++++c4).display();
	cout<<"c4++++++=";(c4++++++).display();
	cout<<"(c4++++++)表达式完成后的c4=";c4.display();
	return 0;
}
