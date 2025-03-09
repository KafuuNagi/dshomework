#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
 srand(time(0));
 int l=100000;
 double a[l];
 //输入 
 for(int i=0;i<l;i++)
  a[i]=(rand()%l)/100.0;
 //处理
 bool changed=false;
 double timer=time(NULL); 
 for(int i=l;i>0;i--)
 {
  changed=false;
  for(int j=1;j<i;j++)
   if(a[j-1]>a[j])
   {
    swap(a[j-1],a[j]);
    changed=true; 
   }
  if(!changed) 
   break;
 }  
 cout<<"处理数据所运行时间："<<time(NULL)-timer<<"秒"<<endl;
 //输出
 int ab;
 cout<<"是否输出?(1为是，0为否)";
 cin>>ab;
 if(!ab)
  return 0;
 for(int i=0;i<l;i++)
 {
  cout<<a[i]<<"  "; 
  if((i+1)%5==0)
   cout<<endl;
 }
 system("pause");
 return 0;
}
