#include<bits/stdc++.h>
using namespace std;

/**------- ShortCuts----------*/
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<int, int>        pii;
typedef pair<int, pii>        iii;
typedef vector<int>           vi;
typedef vector<pii>           vii;
typedef vector<iii>           viii;

/**------- Scanf----------*/
#define sf                 scanf
#define sfi(a)             scanf("%d", &a)
#define sfc(a)             scanf("%c", &a)
#define sfl(a)             scanf("%lld", &a)
#define sfu(a)             scanf("%llu", &a)

#define sfii(a, b)         scanf("%d %d", &a, &b)
#define sfll(a, b)         scanf("%lld %lld", &a, &b)
#define sfuu(a, b)         scanf("%llu %llu", &a, &b)

#define sfiii(a, b, c)     scanf("%d %d %d", &a, &b, &c)
#define sflll(a, b, c)     scanf("%lld %lld %lld", &a, &b, &c)
#define sfuuu(a, b, c)     scanf("%llu %llu %llu", &a, &b, &c)

/**------- Printf----------*/
#define pf                 printf
#define pfi(a)             printf("%d\n", a)
#define pfc(a)             printf("%c\n", a)
#define pfl(a)             printf("%lld\n", a)
#define pfu(a)             printf("%llu\n", a)

#define pfii(a, b)         printf("%d %d\n", a, b)
#define pfll(a, b)         printf("%lld %lld\n", a, b)
#define pfuu(a, b)         printf("%llu %llu\n", a, b)

#define pfiii(a, b, c)     printf("%d %d %d\n", a, b, c)
#define pflll(a, b, c)     printf("%lld %lld %lld\n", a, b, c)
#define pfuuu(a, b, c)     printf("%llu %llu %llu\n", a, b, c)
#define pnl                printf("\n")

/**--------File------------*/
#define output             freopen("output.txt","w",stdout)
#define input              freopen("input.txt","r",stdin)
#define inOut              input; output

/**--------Constant------------*/
#define mx5                100001
#define mx6                1000001
#define fr0(i, n)          for(int i=0; i<n; i++)
#define fr1(i, n)          for(int i=1; i<=n; i++)
#define FF                 first
#define SE                 second
#define all(x)             x.begin(), x.end()
#define INF                0x3f3f3f3f
#define eps                1e-8
#define PI                 acos(-1.0)
#define sq(x)              (x)*(x)
#define FasterIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define UNIQ(a)            sort(all(a));a.erase(unique(all(a)),a.end())
#define mem(x, y)          memset(x, y, sizeof(x))
#define TestCases          int cases, tc; sfi(tc); \
                           for(cases=1; cases<=tc; cases++)

/**--------DeBug------------*/
#define watch(x)           cout<<(#x)<<" is "<<x<<"\n"
#define chk                cout<<"Wtf"<<"\n"

/// memset dp -1 required
long long dp[100][100], n = 10;
int call(int x, int y){
    if(x+y == (n<<1)) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 0;
    if(x < n) ans += call(x+1, y);
    if(y < x) ans += call(x, y+1);
    return dp[x][y] = ans;
}

/// return nCr fastest way
long long findNCR(long long n, long long r)
{
    if(r > n-r) r = n - r;
    long long ans = 1, i;
    for(i=0; i<r; i++){
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

/// return catalan number
/// from the formula
/// Cn = (2n) C (n) - (2n) C (n+1)
/// requirement nCr
long long catalan(int x){
    return findNCR(x<<1, x) - findNCR(x<<1, x+1);
}

int main()
{
    /// inOut;
    memset(dp, -1, sizeof dp);
    cout<<call(0, 0)<<endl;
    cout<<catalan(n)<<endl;
    return 0;
}

