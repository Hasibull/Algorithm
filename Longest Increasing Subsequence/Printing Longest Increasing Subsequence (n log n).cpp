#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi ara{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
int n = ara.size();

int ceilInx(vi &tail, int l, int r, int key)
{
    while(r-l > 1){
        int m = l + (r-l)/2;
        if(ara[tail[m]] >= key) r = m;
        else l = m;
    }
    return r;
}

vi printLis()
{
    vi ans;
    vi tailInx(n, 0);
    vi prevInx(n, -1);

    int len = 1;
    for(int i=1; i<n; i++){
        if(ara[i] < ara[tailInx[0]]) tailInx[0] = i; /// replace smallest value

        else if(ara[i] > ara[tailInx[len-1]]){ /// add new max value
            prevInx[i] = tailInx[len-1];
            tailInx[len++] = i;
        }

        else{
            int pos = ceilInx(tailInx, -1, len-1, ara[i]);
            prevInx[i] = tailInx[pos-1];
            tailInx[pos] = i;
        }
    }

    for(int i=tailInx[len-1]; i>=0; i = prevInx[i])
        ans.push_back(ara[i]);
    reverse(ans.begin(), ans.end());

    return ans;
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
    print(ans);
    return 0;
}
