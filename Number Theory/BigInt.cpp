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

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a){
    while(a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void Print(BigInt a){
    Set(a);
    if(!a.size()) puts("0");
    else{
        for(int i=a.size()-1; i>=0; i--)
            printf("%d", a[i]);
        puts("");
    }
}

BigInt Integer(string s){
    BigInt ans;
    if(s[0] == '-') return ans;
    if(s.size() == 0) {ans.push_back(0); return ans;}
    while(s.size()%9 != 0) s = '0' + s;
    for(int i=0; i<s.size(); i+=9){
        int v = 0;
        for(int j=i; j<i+9; j++) v = v*10 + (s[j] - '0');
        ans.insert(ans.begin(), v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(long long x){
    string s = "";
    while(x) s = char(x%10 + '0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x){
    return Integer((long long)x);
}

void operator >> (istream &in, BigInt &a){
    string s; in>>s;
    a = Integer(s);
}

void operator << (ostream &out, BigInt a){Print(a);}

bool operator < (BigInt a, BigInt b){
    Set(a); Set(b);
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i=a.size()-1; i>=0; i--)
        if(a[i] != b[i])
            return a[i] < b[i];
    return false;
}

bool operator > (BigInt a, BigInt b){return (b < a);}
bool operator == (BigInt a, BigInt b){return !(a<b) && !(b < a);}
bool operator <= (BigInt a, BigInt b){return a<b || a==b;}
bool operator >= (BigInt a, BigInt b){return b<a || a==b;}
bool operator < (BigInt a, int b){return a<Integer(b);}
bool operator > (BigInt a, int b){return a>Integer(b);}
bool operator == (BigInt a, int b){return a == Integer(b);}
bool operator >= (BigInt a, int b){return a >= Integer(b);}
bool operator <= (BigInt a, int b){return a <= Integer(b);}
bool operator < (BigInt a, long long b){return a<Integer(b);}
bool operator > (BigInt a, long long b){return a>Integer(b);}
bool operator == (BigInt a, long long b){return a == Integer(b);}
bool operator >= (BigInt a, long long b){return a >= Integer(b);}
bool operator <= (BigInt a, long long b){return a <= Integer(b);}
bool operator < (BigInt a, string b){return a<Integer(b);}
bool operator > (BigInt a, string b){return a>Integer(b);}
bool operator == (BigInt a, string b){return a == Integer(b);}
bool operator >= (BigInt a, string b){return a >= Integer(b);}
bool operator <= (BigInt a, string b){return a <= Integer(b);}

BigInt max(BigInt a, BigInt b){return a>b?a:b;}
BigInt min(BigInt a, BigInt b){return a<b?a:b;}

BigInt operator + (BigInt a, BigInt b){
    Set(a); Set(b);
    BigInt ans; int carry = 0, sz = max(a.size(), b.size());
    for(int i=0; i<sz; i++){
        if(i < a.size()) carry += a[i];
        if(i < b.size()) carry += b[i];
        ans.push_back(carry%base);
        carry /= base;
    }
    if(carry) ans.push_back(carry);
    Set(ans);
    return ans;
}

BigInt operator + (BigInt a, int b) {return a+Integer(b);}
BigInt operator + (BigInt a, long long b) {return a+Integer(b);}
BigInt operator + (BigInt a, string b) {return a+Integer(b);}
BigInt operator ++ (BigInt &a){return a = a + 1;}
BigInt operator += (BigInt &a, BigInt b) {return a = a + b;}
BigInt operator += (BigInt &a, int b) {return a = a + Integer(b);}
BigInt operator += (BigInt &a, string b) {return a = a + Integer(b);}
BigInt operator += (BigInt &a, long long b) {return a = a + Integer(b);}

BigInt operator - (BigInt a, BigInt b){
    Set(a); Set(b);
    BigInt ans; int carry = 0;
    for(int i=0; i<a.size(); i++){
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if(carry < 0) ans.push_back(carry + base), carry = -1;
        else ans.push_back(carry), carry = 0;
    }
    Set(ans); return ans;
}

BigInt operator - (BigInt a, int b) {return a-Integer(b);}
BigInt operator - (BigInt a, long long b) {return a-Integer(b);}
BigInt operator - (BigInt a, string b) {return a-Integer(b);}
BigInt operator -- (BigInt &a){return a = a - 1;}
BigInt operator -= (BigInt &a, BigInt b) {return a = a - b;}
BigInt operator -= (BigInt &a, int b) {return a = a - Integer(b);}
BigInt operator -= (BigInt &a, string b) {return a = a - Integer(b);}
BigInt operator -= (BigInt &a, long long b) {return a = a - Integer(b);}

BigInt operator * (BigInt a, BigInt b){
    Set(a); Set(b);
    BigInt ans;
    ans.assign(a.size() + b.size(), 0);
    for(int i=0; i<a.size(); i++){
        long long carry = 0LL;
        for(int j=0; j<b.size() || carry > 0; j++){
            long long s = ans[i+j] + carry + (long long)a[i] * (j < b.size() ? (long long)b[j]:0LL);
            ans[i+j] = s % base;
            carry = s / base;
        }
    }
    Set(ans); return ans;
}

BigInt operator * (BigInt a, int b){return a * Integer(b);}
BigInt operator * (BigInt a, string b){return a * Integer(b);}
BigInt operator * (BigInt a, long long b){return a * Integer(b);}
BigInt operator *= (BigInt &a, int b){return a = a * Integer(b);}
BigInt operator *= (BigInt &a, string b){return a = a * Integer(b);}
BigInt operator *= (BigInt &a, long long b){return a = a * Integer(b);}

BigInt operator / (BigInt a, BigInt b){
    Set(a); Set(b);
    if(b == Integer(0)) return Integer(0);
    BigInt ans, cur;
    for(int i=a.size()-1; i>=0; i--){
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while(L <= R){
            int mid = (L+R) >> 1;
            if(b * Integer(mid) > cur){
                x = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        cur = cur - Integer(x-1) * b;
        ans.insert(ans.begin(), x-1);
    }
    Set(ans); return ans;
}

BigInt operator / (BigInt a, string b){return a / Integer(b);}
BigInt operator / (BigInt a, long long b){
    Set(a); BigInt ans;
    long long cur = 0LL;
    for(int i=a.size()-1; i>=0; i--){
        cur = (cur * (long long)base + (long long)a[i]);
        ans.insert(ans.begin(), cur/b);
        cur %= b;
    }
    Set(ans); return ans;
}
BigInt operator / (BigInt a, int b){return a / (long long)b;}
BigInt operator /= (BigInt &a, BigInt b){return a = a/b;}
BigInt operator /= (BigInt &a, int b){return a = a/b;}
BigInt operator /= (BigInt &a, string b){return a = a/b;}
BigInt operator /= (BigInt &a, long long b){return a = a/b;}

BigInt operator % (BigInt a, BigInt b){
    Set(a); Set(b);
    if(b == Integer(0)) return Integer(-1);
    BigInt ans;
    for(int i=a.size()-1; i>=0; i--){
        ans.insert(ans.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while(L <= R){
            int mid = (L+R) >> 1;
            if(b * Integer(mid) > ans){
                x = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        ans = ans - Integer(x-1) * b;
    }
    Set(ans); return ans;
}

BigInt operator % (BigInt a, string b) {return a%Integer(b);}
long long operator % (BigInt a, long long b){
    Set(a);
    if(!b) return -1;
    int ans = 0;
    for(int i=a.size()-1; i>=0; i--)
        ans = (ans * (base%b) + a[i]%b)%b;
    return ans;
}
long long operator % (BigInt a, int b){return a%(long long)b;}
BigInt operator %= (BigInt &a, BigInt b){return a = a%b;}
BigInt operator %= (BigInt &a, string b){return a = a%b;}
BigInt operator %= (BigInt &a, int b){return a = a%Integer(b);}
BigInt operator %= (BigInt &a, long long b){return a = a%Integer(b);}

BigInt gcd(BigInt a, BigInt b){
    Set(a); Set(b);
    while(b > Integer(0)){
        BigInt r = a%b;
        a = b;
        b = r;
    }
    Set(a); return a;
}

BigInt lcm(BigInt a, BigInt b){return (a*b / gcd(a,b));}
BigInt sqrt(BigInt a){
    BigInt x0 = a, x1 = (a+1)/2;
    while(x1 < x0){
        x0 = x1;
        x1 = (x1 + a/x1)/2;
    }
    return x0;
}

BigInt power(BigInt a, BigInt b){
    if(b == Integer(0)) return Integer(1);
    BigInt tmp = power(a, b/2);
    if(b%2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}

BigInt power(BigInt a, int b) {return power(a, Integer(b));}
BigInt power(BigInt a, string b) {return power(a, Integer(b));}
BigInt power(BigInt a, long long b) {return power(a, Integer(b));}

int log(int n, BigInt a){
    Set(a); int ans = 0;
    while(a > Integer(1)){
        ans++;
        a /= n;
    }
    return ans;
}

int main()
{
    /// inOut;
    BigInt a = Integer("123456789123456789123456789");
    BigInt b = Integer(123456789LL);
    int x = 123456789;

    return 0;
}

