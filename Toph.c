P:1
Input	
79 101
Output
Yes
Input	
23 31
Output
No
#include<stdio.h>
int main(){
	int t,p;
	scanf("%d%d",&t,&p);
	int change=p-t;
	int f_coin=1<<1;
	if((change & f_coin)!=0){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
OR
#include <stdio.h>

int main() {
  int t, p;
  scanf("%d", &t);
  scanf("%d", &p);
  int coins[] = {32, 16, 8, 4, 2, 1};
  int amount = p - t;
  int key = -1;
  for (int i = 0; i < 6; i++) {
    if (coins[i] <= amount) {
      if (i == 4)
        key = 1;
      amount = amount - coins[i];
    }
    if (amount <= 0) {
      break;
    }
  }
  if (key == 1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}


P:2
Input	
1
3
32 20
8 10
93 30
2
27
25
Output
64
  
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int N, int P[], int W[], int F, int FW[]) {
    int dp[101][31] = {0};

    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= 30; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (W[i - 1] <= w) {
                dp[i][w] = max(P[i - 1] + dp[i - 1][w - W[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < F; i++) {
        result += dp[N][FW[i]];
    }

    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, F;
        scanf("%d", &N);

        int P[100], W[100];
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &P[i], &W[i]);
        }

        scanf("%d", &F);
        int FW[100];
        for (int i = 0; i < F; i++) {
            scanf("%d", &FW[i]);
        }

        int result = knapsack(N, P, W, F, FW);
        printf("%d\n", result);
    }

    return 0;
}
