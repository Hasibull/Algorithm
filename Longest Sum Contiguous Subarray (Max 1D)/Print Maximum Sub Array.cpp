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

struct maxAra
{
    int x;
    int y;
    int value;
};

struct maxAra maxSum()
{
    struct maxAra ans;
    int maxAns = INT_MIN, maxTmp = 0, start, end, s;
    start = end = s;

    for(int i=0; i<n; i++){
        maxTmp += ara[i];
        if(maxAns < maxTmp){
            maxAns = maxTmp;
            start = s;
            end = i;
        }
        if(maxTmp < 0){
            maxTmp = 0;
            s = i+1;
        }
    }

    ans.x = start, ans.y = end, ans.value = maxAns;
    return ans;
}

int main()
{
    struct maxAra ans = maxSum();
    cout<<"Start     : "
        <<ans.x
        <<endl
        <<"End       : "
        <<ans.y
        <<endl
        <<"Max Value : "
        <<ans.value
        <<endl;

    return 0;
}
