#include <bits/stdc++.h>
using namespace std;
#define mem(a,v) memset((a), v, sizeof(a))

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val)/sizeof(val[0]);

int KS()
{
    int dp[W+1]; mem(dp, 0);

    for(int i=0; i<n; i++)
        for(int w=W; w>=wt[i]; w--)
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);

    return dp[W];
}

int main()
{
    cout<<KS()<<endl;
    return 0;
}


