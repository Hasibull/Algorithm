#include <bits/stdc++.h>
using namespace std;

/**------- Loops----------*/
#define rep1(i, n) 	    for(int i=1; i<=n; i++)
#define rep0(i, n) 	    for(int i=0; i<n; i++)
#define repFI(i, k, n) 	for(int i=k; i<=n; i++)
#define repFE(i, k, n) 	for(int i=k; i<n; i++)
#define repBI(i, k, n) 	for(int i=k; i>=n; i--)
#define repBE(i, k, n) 	for(int i=k; i>n; i--)
#define TRvi(c, it) 	for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it)	for(vii::iterator it = (c).begin(); it != (c).end(); it++)

/**------- ShortCuts----------*/
typedef long long 		    ll;
typedef unsigned long long 	ull;
typedef double              db;
typedef long double         ldb;
typedef pair<int, int> 		ii;
typedef pair<int, ii> 		iii;
typedef vector<int> 		vi;
typedef vector<ii> 		    vii;
typedef vector<iii> 		viii;

/**------- Useful Functions----------*/
template<typename T> T sqr(T a_) { return a_*a_; }
template<typename T> T cub(T a_) { return a_*a_*a_; }
#define copyAra(src, size, des)  	copy_n(src, size, des)
#define numberOfDigits(x) 		    floor(log10(x))+1
#define output        			    freopen("output.txt","w",stdout)
#define input        			    freopen("input.txt","r",stdin)
#define FasterIO     			    ios_base::sync_with_stdio(false);cin.tie(NULL)
#define UNIQ(a)     			    sort(all(a));a.erase(unique(all(a)),a.end())

template<class T> T power(T N,T P);
template<typename T> void print(T n);
template<typename T> void printList(initializer_list<T> value);
template<typename T> void printList(T const& vec);
inline int dbcmp(db a, db b);
inline db dbdiv(int a, int b);
void fastScan(int &number);

/**------- Bit manipulation ----------*/
#define isPowerofTwo(x)         (x &&(!(x&(x-1))))
#define allBitsAreSet(n)        !((n+1)&n)
#define bitsAreInAltOrder(n)    !allBitsAreSet(n^(n>>1))
#define set(num, pos)           num |=(1<<pos)
#define unset(num, pos)         num &= (~(1<<pos))
#define toggle(num, pos)        num ^= (1<<pos)
#define isSet(num, pos)         num&(1<<pos)
#define stripLastBit(num)       num &= (num-1)
#define lowestBit(num)          num &= (-num)
#define clearMSBtoi(num, pos)   num &= ((1<<pos)-1)
#define msb(n) {n |=(n>>1)|(n>>2)|(n>>4)|(n>>8)|(n>>16); n++; (n>>=1);}

/**------- Debug---------*/
#define watch(x)            cout << (#x) << " is " << (x) << endl
#define debug               cout<<"debug"<<endl

/**------- Others---------*/
#define pb            		 push_back
#define ff           	     first
#define ss           		 second
#define all(a)        		 (a).begin(), (a).end()
#define mem(a,v)      		 memset((a), v, sizeof(a))
#define min3(a,b,c)   		 min(a,min(b,c))
#define max3(a,b,c)   		 max(a,max(b,c))
#define ABS(x)        		 ((x)<0?-(x):(x))
#define PI            		 acos(-1.0)
#define INF           		 0x3f3f3f3f
#define mod           		 1000000007
#define oo			         1e15
#define eps			         1e-8
#define SP(n)                fixed<<setprecision(n)
#define mxn           		 100010
#pragma GCC optimize         ("O2")

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int xx[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};

/// KX-> Knight moves
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{

    return 0;
}

template<class T> T power(T N,T P)
{return (P==0)?  1: N*power(N,P-1);}

template<typename T>
void printList(initializer_list<T> value)
{
    int i = 0;
    for(const auto &val:value){
        if(i++) cout<<" ";
        cout<<val;
    }
    cout<<endl;
}

template <typename T>
void printList(T const& vec)
{
    for(auto x:vec)
        cout<<x<<" ";
    cout<<endl;
}

template<typename T>
void print(T n)
{
    bool neg = 0;
    if(n < 0) n *= -1, neg = 1;

    char snum[65]; int i = 0;
    do{
        snum[i++] = n%10 + '0';
        n /= 10;
    }while(n);

    i--;
    if(neg) putchar('-');
    while(i>=0) putchar(snum[i--]);
    putchar('\n');
}

void fastScan(int &number)
{
    bool neg = 0; number = 0;
    register int c;

    c = getchar();
    if(c == '-') neg = 1, c = getchar();
    for(; c>47 && c<58; c=getchar())
        number = number * 10 + c - 48;
    if(neg) number *= -1;
}

inline int dbcmp(db a, db b)	    {return (fabs(a-b)<eps)?0:(a<b?-1:1);}
inline db dbdiv(int a, int b) 		{return static_cast<double>(a)/b;}

