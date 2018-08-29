#include <bits/stdc++.h>
using namespace std;

int n = 4, src = 0;
int dist[10][10] = {
        {0,20,42,35},
        {20,0,30,34},
        {42,30,0,12},
        {35,34,12,0}
};
int VISITED_ALL = (1<<n) - 1;
int dp[16][4];

int tsp(int mask, int pos)
{
    if(mask == VISITED_ALL) return dist[pos][src];
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = 1e9;
    for(int i=0; i<n; i++)
        if(!(mask & (1 << i))){
            int newAns = dist[pos][i] + tsp(mask|(1<<i), i);
            ans = min(ans, newAns);
        }

    return dp[mask][pos] = ans;
}

int main()
{
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++)
            dp[i][j] = -1;

    cout<<tsp(1, src)<<endl;

    return 0;
}
