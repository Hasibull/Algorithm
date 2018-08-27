#include <bits/stdc++.h>
using namespace std;

/// Time Complexity O(coins * value)
/// Memory Complexity O(coins * value)

int coins[] = {1, 2, 3};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 100;

int dp[100][1001]; /// can be solve only when 100 coins and value less then 1001
int countWays(int idx, int val)
{
    if(val == 0) return 1;

    if(val < 0 || idx == n) return 0;

    if(dp[idx][val] != -1) return dp[idx][val];

    int ans = 0;
    if(val >= coins[idx]) ans = countWays(idx, val-coins[idx]);
    ans += countWays(idx+1, val);
    return dp[idx][val] = ans;
}

int main()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<=V; j++)
            dp[i][j] = -1;

    cout<<countWays(0, V)<<endl;

    return 0;
}

