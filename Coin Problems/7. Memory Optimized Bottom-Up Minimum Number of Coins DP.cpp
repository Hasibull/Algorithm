#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int coins[] =  {9, 6, 5, 1};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 11;

int minCoins()
{
    int dp[V+1];
    fill(dp, dp+V+1, INF);
    dp[0] = 0;

    for(int i=1; i<=V; i++)
        for(int j=0; j<n; j++)
            if(coins[j] <=
               i)
                dp[i] = min(dp[i], dp[i - coins[j]]+1);

    return dp[V];
}

int main()
{
    cout<<minCoins()<<endl;
    return 0;
}
