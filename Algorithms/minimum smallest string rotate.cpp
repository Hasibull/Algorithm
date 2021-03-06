
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

/// minimum smallest string rotation

/// booth algorithm
int boothAlgo(string &s){
    s += s; int k = 0;
    vector<int> f(s.size(), -1);
    for(int j=1; j<s.size(); j++){
        char sj = s[j];
        int i = f[j-k-1];
        while(i!=-1 && sj != s[k+i+1]){
            if(sj < s[k+i+1])
                k = j - i - 1;
            i = f[i];
        }
        if(sj != s[k+i+1]){
            if(sj < s[k]) k = j;
            f[j - k] = -1;
        }
        else f[j - k] = i + 1;
    }
    return k;
}

/// greedy approch, easy to implement
int smallestCycle(string &s){
    s += s; int os = 0, ans = 0;
    for(int i=1; i<s.size(); i++)
        if(s[i] < s[ans]) ans=i, os=0;
        else if(s[i] == s[ans+os]) os++;
        else if(s[i]  < s[ans+os])
            ans=i-os, os=0, i=ans;
        else os = 0;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    cout << smallestCycle(s) << "\n";
    cout << boothAlgo(s) << "\n";

    return 0;
}
