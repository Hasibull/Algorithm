#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/// Printing longest increasing subsequence (lis)
/// time complexity O(n^2)
/// memory complexity O(n^2)

vi ara{ 3, 2, 6, 4, 5, 1 }; /// main Array
int n = ara.size();         /// size of array
vector<vi> LIS(n);          /// 2D vector for storing all increasing subsequence

vi printLis()
{
    vi mx; mx.push_back(ara[0]); /// initially 1st value is the answer
    LIS[0].push_back(ara[0]);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++)
            if(ara[j] < ara[i] && LIS[i].size() < LIS[j].size()+1)
                LIS[i] = LIS[j];

        LIS[i].push_back(ara[i]);                  /// storing each i value to the end
        if(mx.size() < LIS[i].size()) mx = LIS[i]; /// largest size of vector is our answer
    }

    return mx;
}

void print(vi ans)
{
    cout<<"Size : "<<ans.size()<<endl;
    for(auto x : ans) /// auto keyword since c++11
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
    vi ans = printLis();
    print(ans);     /// vector printing function
    return 0;
}
