#include <bits/stdc++.h>
using namespace std;

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int  W = 50;
int n = sizeof(val)/sizeof(val[0]);

int KS(int idx, int w)
{
    if(idx == n || w == 0) return 0;
    if(wt[idx] > w) return KS(idx+1, w);
    return max(val[idx]+KS(idx+1, w-wt[idx]), KS(idx+1, w));
}

int main()
{
    cout<<KS(0, W)<<endl;
    return 0;
}
