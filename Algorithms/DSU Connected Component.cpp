#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5+5;
int par[mx], sz[mx], vis[mx];

/** based on size */
void make_set(int u){par[u]=u; sz[u]=1;}
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int u, v, n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        make_set(i);

    while(m--){
        cin >> u >> v;
        union_set(u, v);
    }

    /**
    if query for u and v is in the
    same connected graph or not ?

    int q; cin >> q;
    while(q--){
        cin >> u >> v;
        if(find_set(u) == find_set(v))
            cout << "yes\n";
        else cout << "no\n";
    }
    */

    int ans = 0;
    memset(vis, 0, sizeof vis);
    for(int i=1; i<=n; i++)
        vis[find_set(i)] = 1;
    for(int i=1; i<=n; i++)
        ans += vis[i];
    cout << ans << "\n";

    return 0;
}

