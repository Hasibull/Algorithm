#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int coins[] =  {9, 6, 5, 1};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 11;

int dp[1001]; ///can be solve value upto 1000;
int minCoins(int val)
{
    if(val == 0) return 0;
    if(dp[val] != -1) return dp[val];

    int res = INF;
    for(int i=0; i<n; i++)
        if(coins[i] <= val){
            int sub_res = minCoins(val - coins[i]);
            res = min(res, sub_res+1);
        }

    return dp[val] = res;
}

int main()
{
    fill(dp, dp+V+1, -1);
    cout<<minCoins(V)<<endl;
    return 0;
}

