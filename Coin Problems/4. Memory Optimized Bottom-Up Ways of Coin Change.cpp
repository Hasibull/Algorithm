#include <bits/stdc++.h>
using namespace std;

/// Time Complexity O(coins * value)
/// Memory Complexity O(value)

int coins[] = {1, 2, 3};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 100;

int countWays()
{
    int table[V+1]; fill(table, table+V+1, 0);
    table[0] = 1;

    for(int i=0; i<n; i++)
        for(int j=coins[i]; j<=V; j++)
            table[j] += table[j - coins[i]];

    return table[V];
}

int main()
{
    cout<<countWays()<<endl;
    return 0;
}
