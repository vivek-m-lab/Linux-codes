#include<iostream>
#include<string.h>
using namespace std;
class A
{
public:
char *ptr;
A()
{
cout<<"Defualt constructor "<<endl;
}
A(const char *p)
{
ptr=new char[strlen(p)+1];
strcpy(ptr,p);
}
void modify()
{
ptr[0]='s';
}
};
int main()
{
A ob1("vector");
cout<<"string of ob1 = "<<ob1.ptr<<endl;
A ob2;
ob2=ob1;
cout<<"String of ob2 = "<<ob2.ptr<<endl;
ob2.modify();
cout<<"string of ob1 after modification = "<<ob1.ptr<<endl;
cout<<"String of ob2 after modification = "<<ob2.ptr<<endl;


}
