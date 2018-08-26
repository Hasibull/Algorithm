#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/// longest increasing subsequence (lis)
/// time complexity O(n log n)
/// memory complexity O(n)

vi vec{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; /// main container / array
vi tail(vec.size(), 0);

int lisLen()
{
    int len = 1; tail[0] = vec[0];
    for(size_t i=1; i<vec.size(); i++){
        if(vec[i] < tail[0]) tail[0] = vec[i];
        else if(vec[i] > tail[len-1]) tail[len++] = vec[i];
        else {
            auto it = tail.begin();
            int ix = lower_bound(it, it+len, vec[i]) - it; /// O(log n)
            tail[ix] = vec[i];
        }
    }
    return len;
}

int main()
{
    cout<<lisLen()<<endl;
    return 0;
}
