#include<stdio.h>
char A[100];
char B[100];
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
        return b;
}
int dp[100][100];

int lcs(int m, int n)
{
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {

            if(i==0 || j==0)
            {
                dp[i][j]= 0;
            }
            else if(A[i]==B[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);

        }
    }
    return dp[m][n];
}

int main()
{
    gets(A);
    gets(B);
    int m = strlen(A);
    int n = strlen(B);
    printf("%d",lcs(m,n));

}


