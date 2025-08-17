#include<iostream>
using namespace std;
class A
{
public:
int x;
A()
{
cout<<"Enter the data"<<endl;
cin>>x;
}
friend void print();
friend void swap(A &a,A &b);
};
void print(A &a,A &b)
{
cout<<"ob1 data = "<<a.x<<endl;
cout<<"ob2 data = "<<b.x<<endl;
}
void swap(A &a,A &b)
{
int temp;
temp=a.x;
a.x=b.x;
b.x=temp;
}
int main()
{
A ob1;
A ob2;
print(ob1,ob2);
swap(ob1,ob2);
print(ob1,ob2);
}
