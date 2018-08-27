#include <bits/stdc++.h>
using namespace std;

/// Time Complexity O(coins * value)
/// Memory Complexity O(coins * value)

int coins[] = {1, 2, 3};
int n = sizeof(coins)/sizeof(coins[0]);
int V = 100;

int countWays()
{
    int table[V+1][n];
    for(int i=0; i<n; i++) table[0][i] = 1;

    for(int i=1; i<=V; i++){
        for(int j=0; j<n; j++){
            int x = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;
            int y = (j >= 1) ? table[i][j-1] : 0;
            table[i][j] = x + y;
        }
    }

    return table[V][n-1];
}

int main()
{
    cout<<countWays()<<endl;
    return 0;
}


