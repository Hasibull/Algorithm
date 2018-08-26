#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/// longest increasing subsequence (lis)
/// time complexity O(n^2)
/// memory complexity O(n)

vi ara{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; /// main container / array
int n = ara.size();

int lisLen()
{
    int dp[n], ans = 1; fill(dp, dp+n, 1);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(ara[j] < ara[i]){
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
    return ans;
}

int main()
{
    cout<<lisLen()<<endl;
    return 0;
}
