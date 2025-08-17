#include<iostream>
using namespace std;
class wife;
class husband
{
int x;
char name[20];
public:
void setdata()
{
cout<<"Enter the Husband name :"<<endl;
cin.getline(name,20);
cout<<"Enter the Husband salary "<<endl;
cin>>x;
cin.ignore();
}
void print()
{
cout<<"Husband details"<<endl;
cout<<"Name :"<<name<<endl;
cout<<"Salary :"<<x<<endl;
}
friend void total(husband &ob3,wife &ob4);
};
class wife
{
int y;
char name[20];
public:
void setdata()
{
cout<<"Enter the wife name"<<endl;
cin.getline(name,20);
cout<<"Enter the wife salary"<<endl;
cin>>y;
}
void print()
{
cout<<"Wife details "<<endl;
cout<<"Name : "<<name<<endl;
cout<<"Salary : "<<y<<endl;
}
friend void total(husband &ob3,wife &ob4);
};
void total(husband &ob3,wife &ob4)
{
int tot;
tot=ob3.x+ob4.y;
cout<<"Total salary : "<<tot<<endl;
}
int main()
{
husband ob1;
wife ob2;
ob1.setdata();
ob2.setdata();
ob1.print();
ob2.print();

total(ob1,ob2);
}

