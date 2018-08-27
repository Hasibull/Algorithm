#include <bits/stdc++.h>
using namespace std;
#define mem(a,v) memset((a), v, sizeof(a))

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val)/sizeof(val[0]);

int dp[100][1001];
int KS(int idx, int w)
{
    if(idx == n || w == 0) return 0;

    if(dp[idx][w] != -1) return dp[idx][w];

    if(wt[idx] > w) return dp[idx][w] = KS(idx+1, w);

    return dp[idx][w] = max(val[idx]+KS(idx+1, w-wt[idx]), KS(idx+1, w));
}

int main()
{
    mem(dp, -1);
    cout<<KS(0, W)<<endl;
    return 0;
}
