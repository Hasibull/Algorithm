#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 3};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 100;

int countWays(int idx, int val)
{
    if(val == 0) return 1;
    if(val < 0 || idx == n) return 0;
    return countWays(idx, val-coins[idx]) + countWays(idx+1, val);
}

int main()
{
    cout<<countWays(0, V)<<endl;
    return 0;
}
