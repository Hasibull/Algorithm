#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

int par[mx], sz[mx], rank[mx];

/** based on size */
int make_set(int u){par[u]=u; sz[u]=1;}
int find_set(int u){
    return u==par[u]?u:par[u]=find_set(par[u]);}
void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u; sz[u] += sz[v];
    }
}

/** based on depth (rank) */
/**
int make_set(int u){par[u]=u; rank[u]=0;}
int find_set(int u){
    return u==par[u]?u:par[u]=find_set(par[u]);}
void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(rank[u] < rank[v]) swap(u, v);
        par[v] = u; if(rank[u]==rank[v]) rank[u]++;
    }
}
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



    return 0;
}

