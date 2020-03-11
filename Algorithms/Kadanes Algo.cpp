#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

struct kadane{
    int best, L, R;
    kadane(vector<int> &a){
        int n = a.size();
        int l=0, cur = 0; best = 0;
        for(int i=0; i<n; i++){
            cur += a[i];
            if(cur < 0) cur = 0, l=i;
            if(best < cur) best=cur, L=l, R=i;
        }
    }
};

struct Kadane2D{
    int best, LR, RR, LC, RC;
    Kadane2D(vector< vector<int> > &a){
        best = 0;
        int n = a.size();
        int m = a[0].size();
        for(int l=0; l<m; l++){
            vector<int> tmp(n, 0);
            for(int r=l; r<m; r++){
                for(int i=0; i<n; i++)
                    tmp[i] += a[i][r];
                kadane kad(tmp);
                if(kad.best > best){
                    best = kad.best;
                    LC = l; RC = r;
                    LR = kad.L, RR = kad.R;
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = 3, m = 3;
    vector< vector<int> > a;
    a.assign(n, vector<int>(m, 0));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    Kadane2D kad(a);
    cout << kad.best << '\n';
    for(int i=kad.LR; i<=kad.RR; i++)
        for(int j=kad.LC; j<=kad.RC; j++)
            cout << a[i][j] << " \n"[j==kad.RC];

    return 0;
}

