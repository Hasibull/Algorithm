
#include <bits/stdc++.h>
using namespace std;

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val)/sizeof(val[0]);

int KS()
{
    int dp[2][W+1];
    for(int i=0, k=i; i<n; i++, k=i%2){
        for(int w=0; w<=W; w++){
            if(!i || !w) dp[k][w] = 0;
            else if(wt[i] > w) dp[k][w] = dp[1-k][w];
            else dp[k][w] = max(dp[1-k][w], val[i]+dp[1-k][w-wt[i]]);
        }
    }
    return dp[1 - n%2][W];
}

int main()
{
    cout<<KS()<<endl;
    return 0;
}

