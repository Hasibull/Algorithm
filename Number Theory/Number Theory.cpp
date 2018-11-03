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

/// return gcd(a, b)
template<typename T>
inline T gcd(T a, T b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

/// return lcm(a, b)
/// requirement gcd(a, b)
template<typename T>
inline T lcm(T a, T b)
{return (a*b)/gcd(a, b);}

#define maxL   (mx >> 5) + 1
#define GET(x) (mark[x>>5] >> (x&31) & 1)
#define SET(x) (mark[x>>5] |= 1 << (x&31))

/// prime numbers are stored
/// in primes upto sqrt(mx)
const long long mx = 1e6 + 5;
unsigned int mark[maxL];
vector<int> primes;

void sieve()
{
    primes.push_back(2); SET(1);
    const long long lim = sqrt(mx);
    register long long i, j, k;
    for(i=3; i<=lim; i+=2)
    if(!GET(i)){
        primes.push_back(i);
        for(j=i*i, k=i+i; j<=lim; j+=k)
            SET(j);
    }
}

/// return number of divisor
/// requirement prime numbers
/// upto sqrt(x)
long long numDiv(long long x)
{
    ll i = 0, p = primes[i], ans = 1;
    while(p*p <= x){
        ll cnt = 0;
        while(x%p == 0) x /= p, cnt++;
        ans *= (cnt + 1);
        p = primes[++i];
    }
    if(x != 1) ans <<= 1;
    return ans;
}

/// return val ^  p (% mod) O(log(p))
template <typename T>
T power(T val, T p, T mod)
{
    val %= mod;
    T result = 1;
    while (p > 0) {
        if (p & 1) result = (result * val) % mod;
        val = (val * val) % mod;
        p >>= 1;
    }
    return result;
}

/// return val ^  p O(log(p))
template <typename T>
T power(T val, T p)
{
    T result = 1;
    while (p > 0) {
        if (p & 1) result = (result * val);
        val = (val * val);
        p >>= 1;
    }
    return result;
}

/// return sum of divisors
/// requirement prime numbers
/// upto sqrt(x)
long long sumDiv(long long x)
{
    ll i = 0, p = primes[i], ans = 1;
    while(p*p <= x){
        ll cnt = 1;
        while(x%p == 0) x /= p, cnt++;
        ans *= ((power(p, cnt) - 1) / (p - 1));
        p = primes[++i];
    }
    if(x != 1) ans *= ((x*x - 1) / (x - 1));
    return ans;
}

/// return the number of coprime
/// with x (coprime = gcd(x, i) == 1 i<x;
/// requirement prime numbers upto sqrt(x)
long long eulerPhiX(long long x)
{
    long long i = 0, p = primes[i], ans = x;
    while(p * p <= x){
        if(x%p == 0) ans -= ans/p;
        while(x%p == 0) x /= p;
        p = primes[++i];
    }
    if(x != 1) ans -= ans/x;
    return ans;
}

/// store number of coprime numbers
/// for each index upto mx
/// based on sieve algorithm
/// const long long mx = 1e6 + 5;
long long phi[mx];
void eulerPhiSieve()
{
    register long long i, j;
    for(i=1; i<mx; i++) phi[i] = i;
    for(i=2; i<mx; i++)
        if(phi[i] == i)
            for(j=i; j<mx; j+=i)
                phi[j] -= phi[j]/i;
}

/// return pair of integer,
/// value of x and y
/// which satisfy ax + by = gcd(a, b)
pii extendedEuclid(int a, int b){
    if(b == 0) return pii(1, 0);
    pii d = extendedEuclid(b, a%b);
    return pii(d.second, d.first - d.second * (a / b));
}

/// return a^(-1) % n
/// requirement extended Euclid theorem
int modInv(int a, int n){
    pii ans = extendedEuclid(a, n);
    return ((ans.first % n) + n) % n;
}

/// returns (a * b) % m;
/// a = 123456789123, b = 123456789123, m = 123456789123
long long modulerMultiplication(long long a, long long b, long long m){
    long long ans = 0; a %= m;
    while(b){
        if(b & 1) ans = (ans + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    /// inOut;
    sieve();
    return 0;
}
