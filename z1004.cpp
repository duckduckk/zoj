#include<iostream>  
#include<stack>  
#include<vector>  
using namespace std;  
string a,b;  
stack<char>build;  
vector<char>save;//容器，相当于动态数组  
int len;  
void dfs(int in,int out)///出入站的个数  
{  
  if(in==len&&out==len)  
  {  
    for(int i=0;i<save.size();i++)  
    cout<<save[i]<<" ";cout<<"\n";  
  }  
  if(in<len)  
  {  
    build.push(a[in]);  
    save.push_back('i');  
    dfs(in+1,out);  
    build.pop();   //个人理解：因为两个字符串a b,对应着多种情况，所以每次走完后必须得把'地图'还原。先走完，再从后面往前依次还原。
    save.pop_back();  
  }  
  if(out<in&&out<len&&build.top()==b[out])  
  {  
    char _s=build.top();build.pop();  
    save.push_back('o');dfs(in,out+1);  
    build.push(_s);save.pop_back();  
  }  
}  
int main()  
{  
  while(cin>>a>>b)  
  {  
    len=a.length();  
    cout<<"["<<"\n";  
    dfs(0,0);  
    cout<<"]"<<"\n";  
  }  
}  
