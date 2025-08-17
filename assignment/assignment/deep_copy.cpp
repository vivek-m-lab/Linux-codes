#include<iostream>
#include<string.h>
using namespace std;
class A
{
char *ptr;
public:
A()
{
cout<<"Defualt constructor"<<endl;
}
public:
A(char *p)
{
cout<<"Parameterised constructor"<<endl;
ptr=new char[strlen(p)+1];
strcpy(ptr,p);
}
void operator=(A &temp)
{
ptr=new char[strlen(temp.ptr)+1];
cout<<"Assignment operators function called"<<endl;
strcpy(ptr,temp.ptr);
}
void modify()
{
cout<<"Modifying"<<endl;
 ptr[0]='s';
}
void print()
{
cout<<"ptr = "<<ptr<<endl;
}
};
int main()
{
A ob1("vector");
cout<<"ob1 ptr data"<<endl;
ob1.print();
A ob2;
cout<<"ob2 ptr data"<<endl;
ob2.print();
ob2=ob1;
cout<<"after update ob1 ptr"<<endl;
ob1.print();
cout<<"after update ob2 ptr"<<endl;
ob2.print();
ob1.modify();
cout<<"after modification ob1 ptr"<<endl;
ob1.print();
cout<<"after modification ob2 ptr"<<endl;
ob2.print();
}
