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

/// a%b (positive value)
inline int mod(int a, int b){
    return ((a%b)+b)%b;
}

/// compute gcd(a, b)
inline int gcd(int a, int b){
    while(b){
        int t = a%b;
        a = b;
        b = t;
    }
    return a;
}

/// compute lcm(a, b)
inline int lcm(int a, int b){
    return a/gcd(a, b) * b;
}

/// compute n^p (mod(m))
inline int powerMod(int n, int p, int m){
    int ret = 1;
    while(p){
        if(p&1) ret = mod(ret*n, m);
        n = mod(n*n, m);
        p >>= 1;
    }
    return ret;
}

/// compute n^p
inline int power(int n, int p){
    int ret = 1;
    while(p){
        if(p&1) ret *= n;
        n *= n;
        p >>= 1;
    }
    return ret;
}

/// return g = gcd(a, b);
/// finds x, y such that g = ax + by;
inline int extendedEuclid(int a, int b, int &x, int &y){
    int xx = y = 0;
    int yy = x = 1;
    while(b){
        int q = a/b;
        int t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }
    return a;
}

/// finds all solutions to ax = b (mod n)
vi moduler_linear_equationSolver(int a, int b, int n){
    int x, y; vi res;
    int g = extendedEuclid(a, n, x, y);
    if(!(b%g)){
        x = mod(x*(b/g), n);
        for(int i=0; i<g; i++)
            res.push_back(mod(x+i*(n/g), n));
    }
    return res;
}

/// https://www.youtube.com/watch?v=shaQZg8bqUM
/// return a^(-1) mod (n)
/// return b such that ab = 1 (mod n)
/// return -1 on failure
inline int mod_inverse(int a, int n){
    int x, y, g = extendedEuclid(a, n, x, y);
    if(g > 1) return -1;
    return mod(x, n);
}

/// chinese remainder theorem (special case)
/// find z such that
/// z%m1 = r1; z%m2 = r2;
/// return (z, M) where M = lcm(m1, m2)
/// on failure, M = -1
pii chinese_remainder_theorem(int m1, int r1, int m2, int r2){
    int s, t, g = extendedEuclid(m1, m2, s, t);
    if(r1%g != r2%g) return {0, -1};
    return {mod(s*r2*m1 + t*r1*m2, m1*m2)/g, m1*m2/g};
}

/// chinese remainder theorem (special case)
/// find z such that
/// z%m[i] = r[i] for all i
/// return (z, M) where M = lcm(m[i] for all i)
/// on failure, M = -1
pii chinese_remainder_theorem(const vi &m, const vi &r){
    pii ret = {r[0], m[0]};
    for(int i=1; i<m.size(); i++){
        ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
        if(ret.second == -1) break;
    }
    return ret;
}

/// computes x and y such that ax + by = c;
/// return whether the solution exists
bool linear_diophantine(int a, int b, int c, int &x, int &y){
    if(!a && !b){
        if(c) return false;
        x = 0; y = 0;
        return true;
    }

    if(!a){
        if(c%b) return false;
        x = 0; y = c/b;
        return true;
    }

    if(!b){
        if(c%a) return false;
        x = c/a; y = 0;
        return true;
    }

    int g = gcd(a, b);
    if(c%g) return false;
    x = c/g * mod_inverse(a/g, b/g);
    y = (c - a*x)/b;
    return true;
}

int main()
{
    /// inOut;
    cout<<gcd(14, 30)<<endl;

    int x, y, g = extendedEuclid(14, 30, x, y);
    cout<<g<<" "<<x<<" "<<y<<endl;

    vi sol = moduler_linear_equationSolver(14, 30, 100);
    fr0(i, sol.size()) cout<<sol[i]<< " " ; cout<<endl;

    cout<<mod_inverse(8, 9)<<endl;

    pii ret = chinese_remainder_theorem(vi({3, 5, 7}), vi({2, 3, 2}));
    cout<<ret.first<<" "<<ret.second<<endl;

    ret = chinese_remainder_theorem(vi({4, 6}), vi({3, 5}));
    cout<<ret.first<<" "<<ret.second<<endl;

    if(!linear_diophantine(7, 2, 5, x, y))
        cout<<"Error"<<endl;
    cout<<x<<" "<<y<<endl;

    return 0;
}

