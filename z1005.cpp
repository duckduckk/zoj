/*个人理解:A可以倒向B，B也可以倒向A。但是最简单的方法事只从A倒向B，使B sucess.倒法有多种，只需选择最简单的一种即可。即可与系统样例匹配*/
/*基本步骤：
1.判断bottle1中是否有水，没有水就灌满水
2.将bottle1中的水放入bottle2中
3.判断bottle2是否等于指定水量，如果没有，那么就将bottle2清空
*/
#include<stdio.h>
int main()
{
   int a,b,p;
   int bottle1,bottle2; 
   while(scanf("%d%d%d",&a,&b,&p)!=EOF)
   {  
      bottle1=0;
      bottle2=0;
      while(1)
      {
        if(bottle1==0)
        {
            bottle1=a;
            printf("fill A\n"); 
        }
        if(bottle2+bottle1<=b)
        {
            bottle2+=bottle1;
            bottle1=0;
        }
        else
        {
            bottle1=bottle1-(b-bottle2);
            bottle2=b; 
        }
        printf("pour A B\n");
        if(bottle2==p)
        {
            printf("success\n");
            break; 
        }
        if(bottle2==b)
        {
            bottle2=0;
            printf("empty B\n"); 
        }
      }
   }
   
   return 0; 
}
