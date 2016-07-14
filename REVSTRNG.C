#include<stdio.h>
#include<conio.h>

int ulta(char *,char *);

void revstring(char *s)
{
 char *wb=s,*t=s;

 while(*t)
 {
  t++;
  if(*t=='\0')
    ulta(wb,t-1);

  else if(*t==' ')
    {
    ulta(wb,t-1);
    wb=t+1;
    }
 }
   ulta(s,t-1);

}

int ulta(char *b,char *e)
{
 char temp;
 while(b<e)
 {
  temp=*b;
  *b=*e;
  *e=temp;
   b++;
   e--;
 }
 return 0;
}


int main(void)
{
 char s[]="i like this very much";
 clrscr();
 printf("%s",s);
 revstring(s);
 printf("\nReverse string is:-%s",s);
 getch();
 return 0;
}