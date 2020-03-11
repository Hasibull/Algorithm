#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define mem(a, v) memset((a), (v), sizeof(a))

const int mxc = 26;
const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

int out[mx], fail[mx], go[mx][mxc];

void build(vector<string> &a){
    int state = 1;
    mem(out,0); mem(fail,-1); mem(go,-1);
    for(int cur=0,i=0; i<a.size(); i++,cur=0){
        const string &word = a[i];
        for(int j=0; j<word.size(); j++){
            int c = word[j] - 'a';
            if(go[cur][c] == -1)
                go[cur][c] = state++;
            cur = go[cur][c];
        }
        out[cur] |= (1<<i);
    }

    queue<int>q;
    for(int c=0; c<mxc; c++)
    if(go[0][c] == -1) go[0][c] = 0;
    else if(go[0][c] != 0)
        fail[go[0][c]] = 0, q.push(go[0][c]);

    while (q.size()) {
      int u = q.front(); q.pop();
      for (int ch = 0; ch < mxc; ++ch) {
         if (go[u][ch] != -1) {
            int f = fail[u];
            while (go[f][ch] == -1) f = fail[f];
            f = go[f][ch]; fail[go[u][ch]] = f;
            out[go[u][ch]] |= out[f];
            q.push(go[u][ch]);
         }
      }
   }
}

int getNext(int p, int c){
    c = c - 'a';
    while(go[p][c] == -1)
        p = fail[p];
    return go[p][c];
}

void aho_search(vector<string> &pat, string &text){
    build(pat); int cur = 0;
    for(int i=0; i<text.size(); i++){
        cur = getNext(cur, text[i]);
        if(out[cur] == 0) continue;
        for(int j=0; j<pat.size(); j++)
            if(out[cur] & (1<<j))
                cout << "Word " << pat[j] << " location: " << (i-pat[j].size()+1) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> pat = {"their", "there", "answer", "any", "bye"};
    string text = "isthereanyanswerokgoodbyebye";
    aho_search(pat, text);


    return 0;
}

