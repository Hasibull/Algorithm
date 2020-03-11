#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

struct info{int u, v, w;
    info(int _u, int _v, int _w):
        u(_u), v(_v), w(_w){}
};

int n, m;
vector<info> ed;
int d[mx], par[mx];

void solve(int s){
    memset(par, -1, sizeof par);
    memset(d, INF, sizeof d);
    d[s] = 0; int x = -1;

    for(int i=0; i<n; i++){x=-1;
        for(int j=0; j<m; j++)
        if(d[ed[j].u] != INF)
        if(d[ed[j].v] > d[ed[j].u]+ed[j].w){
            d[ed[j].v] = d[ed[j].u]+ed[j].w;
            par[ed[j].v] = ed[j].u;
            x = ed[j].v;
        }
    }

    if(x == -1) cout << "no negative cycle\n";
    else{
        int y = x;
        for(int i=0; i<n; i++)
            y = par[y];

        vector<int> path;
        for(int cur=y;; cur=par[cur]){
            path.push_back(cur);
            if(cur==y && path.size()>1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative Cycle :";
        for(int i=0; i<path.size(); i++)
            cout << " " << path[i];
        cout << "\n";
    }
}

void add(int u, int v, int t){
    ed.emplace_back(u, v, t);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    n = 3, m = 3;
    add(0, 1, 1000);
    add(1, 2, 15);
    add(2, 1, -42);

    solve(1);

    return 0;
}

