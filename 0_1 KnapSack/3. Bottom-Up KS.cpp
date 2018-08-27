
#include <bits/stdc++.h>
using namespace std;

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val)/sizeof(val[0]);

int KS()
{
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++)
        for(int w=0; w<=W; w++)
            if(!i || !w) dp[i][w] = 0;
            else if(wt[i-1] > w) dp[i][w] = dp[i-1][w];
            else dp[i][w] = max(dp[i-1][w], val[i-1]+dp[i-1][w-wt[i-1]]);

    return dp[n][W];
}

int main()
{
    cout<<KS()<<endl;
    return 0;
}
