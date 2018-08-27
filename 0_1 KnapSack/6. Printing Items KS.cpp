#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int val[] = { 60, 100, 120 };
int wt[] = { 10, 20, 30 };
int W = 50;
int n = sizeof(val) / sizeof(val[0]);

/// KS function return a vector with the
/// KS value in 0 index and indices of
/// taken items
vi KS()
{
    int dp[n+1][W+1];
    vi ans;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=W; j++)
            if(!i || !j) dp[i][j] = 0;
            else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);

    int res = dp[n][W];
    ans.push_back(res);

    for(int i=n, j=W; i && res; i--)
        if(res == dp[i-1][j]) continue;
        else{
            ans.push_back(i-1);
            res -= val[i-1];
            j -= wt[i-1];
        }

    reverse(ans.begin()+1, ans.end());
    return ans;
}

int main()
{
    vi ans = KS();

    cout<<"Value : "<<ans[0]<<endl;
    cout<<"Items : weight value"<<endl;
    for(int i=1; i<ans.size(); i++)
        cout<<"        "<<wt[ans[i]]<<"     "<<val[ans[i]]<<endl;

    return 0;
}
