#include<stdio.h>
#include<string.h>
//明文字符串
char  plainText[70],cipherText[70];
int plainCode[70],cipherCode[70];
int k,len;
int main()
{
   int i;
   while(1)
   {
      scanf("%d",&k);
      if(k==0)
      {
          break; 
      } 
      scanf("%s",cipherText);
      
      len=strlen(cipherText);
      
      for(i=0;i<len;i++)  //cipherText[]转换成ciperCode[]
      {
         if(cipherText[i]>='a'&&cipherText[i]<='z')
         {
             cipherCode[i]=cipherText[i]-'a'+1; 
         } 
         else if(cipherText[i]=='_')
         {
             cipherCode[i]=0;
         }
         else if(cipherText[i]=='.')
         {
             cipherCode[i]=27;
         }
      }
      for(i=0;i<len;i++)  //cipherCode[]转换成plainCode[]
      {
         plainCode[(i*k)%len]=(cipherCode[i]+i)%28;  //明文和密文的code数组中保存的是0~27的数字，必须都得保证在0~27之间，所以两条公式(本条公式和题目中的公式)都得对28取余。
      }
      for(i=0;i<len;i++)  //plainCode[]转换成plainText[]
      {
         if(plainCode[i]>=1&&plainCode[i]<=26)
         {
            plainText[i]='a'-1+plainCode[i]; 
         } 
         else if(plainCode[i]==0)
         {
            plainText[i]='_'; 
         }
         else if(plainCode[i]==27)
         {
            plainText[i]='.'; 
         }
      }
      for(i=0;i<len;i++)  //输出plainText[]
      {
         printf("%c",plainText[i]); 
      }
      printf("\n");
   }
   return 0; 
}

/*
首先，令plainText为明文字符串数组，cipherText为密文字符串数组，plainCode为明文数字数组，cipherCode为密文数字数组。
1.输入密文，放入cipherText中,len=strlen(cipherText)
2.根据'a'~'z'为1~26，'_'为0，'.'为27，将cipherText转变为数字放入cipherCode中。
3.plainCode[(i*k)%len]=(cipherCode[i]+i)%28 转换过去
4.将plainCode再按上述规则转变为明文数组plainText
5.输出plainText
*/
