#include<iostream>
using namespace std;
class student
{
public:
int rollno;
char name[20];
float m1,m2,m3,tot;
public:
student()
{
cout<<"Enter the Name "<<endl;
cin.getline(name,20);
cout<<"Enter the Roll number"<<endl;
cin>>rollno;
cout<<"Enter the Mark1"<<endl;
cin>>m1;
cout<<"Enter the Mark2"<<endl;
cin>>m2;
cout<<"Enter the Mark3"<<endl;
cin>>m3;
cin.ignore();
}
void total()
{
tot=m1+m2+m3;
}
void print()
{
cout<<"NAME       : "<<name<<endl;
cout<<"Roll.No    : "<<rollno<<endl; 
cout<<"Total mark : "<<tot<<endl;
}
void compare(student &a,student &b)
{
  if(a.tot>b.tot)
{
a.print();
}
else
{
b.print();
}
}
};
int main()
{
student ob1;
student ob2;
ob1.total();
ob2.total();
ob1.print();
ob2.print();
cout<<"Student with Highest number"<<endl;
ob1.compare(ob1,ob2);
}

