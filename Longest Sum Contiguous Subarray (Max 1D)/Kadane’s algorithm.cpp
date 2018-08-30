#include <bits/stdc++.h>
using namespace std;

typedef long long int intl;
typedef unsigned long long intu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define OUTPUT        freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfii(a, b)    scanf("%d %d", &a, &b)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           0x3f3f3f3f
#define mod           1000000007
#define mxn           100010

int ara[] = {-2, -3, 4, -1, -2, 1, 5, -3};
int n = sizeof(ara)/sizeof(ara[0]);

int maxSum()
{
    int maxAns, maxTmp; maxAns = maxTmp = ara[0];

    for(int i=1; i<n; i++){
        maxTmp = max(ara[i], maxTmp+ara[i]);
        maxAns = max(maxAns, maxTmp);
    }

    return maxAns;
}

int main()
{
    cout<<maxSum()<<endl;
    return 0;
}
