#include <bits/stdc++.h>
using namespace std;
#define INF           0x3f3f3f3f

int coins[] =  {9, 6, 5, 1};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 11;

int minCoins(int val)
{
    if(val == 0) return 0;

    int res = INF;
    for(int i=0; i<n; i++)
        if(coins[i] <= val){
            int sub_res = minCoins(val - coins[i]);
            res = min(res, sub_res+1);
        }

    return res;
}

int main()
{
    cout<<minCoins(V)<<endl;
    return 0;
}
