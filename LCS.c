#include<stdio.h>
//#include<string.h>
char A[100];
char B[100];
int main()
{
   //scanf("%s",&A);
   //scanf("%s",&B);
   gets(A);
   gets(B);
   printf("%d",lcs(0,0));

}
int max(int a, int b){
if(a>b){
    return a;
}
    else
        return b;
}



int lcs(int i, int j)
{
    if(A[i]=='\0' || B[j]=='\0' )
    {
        return 0;
    }
    else if(A[i]==B[j])
    {
        return 1+lcs(i+1,j+1);
    }else
    return max(lcs(i+1,j),lcs(i,j+1));

}
