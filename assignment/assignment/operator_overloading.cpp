#include<iostream>
using namespace std;
class A
{
public:
int x,y;
public:
void setdata()
{
cout<<"Enter the data x "<<endl;
cin>>x;
cout<<"Enter the y data "<<endl;
cin>>y;
}
public:
A operator * (A &a)
{
A temp;
temp.x= x*a.x;
temp.y=y*a.y;
return temp;
}
A operator /(A &a)
{
A temp;
temp.x=x/a.x;
temp.y=y/a.y;
return temp;
}
};
int main()
{
A ob1,ob2,ob3,ob4;
ob1.setdata();
ob2.setdata();
ob3.setdata();
ob4=ob1*ob2/ob3;
cout<<"ob4.x = "<<ob4.x<<endl;
cout<<"ob4.y = "<<ob4.y<<endl;
}
