#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

#define pb push_back
#define gp <<' '<<

const int mx = 4e4+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

int par[mx], col[mx];

/** based on size */
void make_set(int u){par[u]=u; col[u]=-1;}
int find_set(int u){
    return u==par[u]?u:par[u]=find_set(par[u]);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m, u, v, tc; cin >> tc;
    while(tc--){
        cin >> m;
        vector<int> vec;
        vector<pii> pairs;
        while(m--){
            cin >> u >> v;
            vec.pb(u);
            vec.pb(v);
            pairs.pb({u, v});
        }

        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        map<int,int> mp;
        for(int i=0; i<vec.size(); i++)
            mp[vec[i]] = i, make_set(i);
        make_set(vec.size());

        for(int i=pairs.size()-1; i>=0; i--){
            u = pairs[i].first; u = mp[u];
            v = pairs[i].second; v = mp[v];
            for(; u<=v; u++){
                u = find_set(u);
                if(u <= v && col[u]==-1)
                    par[u] = v+1, col[u] = i;
            }
        }

        set<int> ans;
        for(int i=0; i<vec.size(); i++)
            ans.insert(col[i]);
        if(ans.count(-1)) ans.erase(-1);
        cout << ans.size() << "\n";
    }

    return 0;
}

