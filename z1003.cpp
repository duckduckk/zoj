#include <cstdio>  
#include <iostream>  
#include <cstring>  
using namespace std ;  
bool aTrue,bTrue ;  
  
int judge(int m,int n,int p)  
{  
    if(m == 1 && n==1)   //按照规则，只要高分者不说谎，则挑战失败，即高分者胜利  
    {  
        aTrue  = true ;  
        return 0 ;  
    }  
    if(n ==1)  
        bTrue = true ;   //此时n==1 && m!=1(即高分的分数无法有效分解，即高分者在说谎)  
    while(p >1)  
    {  
        if(m%p == 0)   //p是m的一个因子  
            judge(m/p,n,p-1) ;  
        if(n%p == 0)   //p是n的一个因子  
            judge(m,n/p,p-1) ;  
        p -- ;  
    }  
    return 0 ;  
}  
  
int main()  
{  
    int a,b ;  
    while(scanf("%d%d",&a,&b)!=EOF)  
    {  
        if(a<b)  
        {  
            int t = a ;  
            a = b;  
            b = t ;  
        }  
        aTrue = false ;  
        bTrue = false ;  
        judge(a,b,100) ;  
        if(!aTrue && bTrue)  
        {  
            printf("%d\n",b) ;  
        }  
        else  
        {  
            printf("%d\n",a) ;  
        }  
    }  
    return 0 ;  
}  
