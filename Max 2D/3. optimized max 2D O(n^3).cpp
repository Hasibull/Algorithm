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

const int row = 4, col = 4;
int ara[row][col] = {
    { 0, -2, -7,  0},
    { 9,  2, -6,  2},
    {-4,  1, -4,  1},
    {-1,  8,  0, -2}
};

int max2D()
{
    int maxRet = INT_MIN, tmpMx, tmp;
    for(int i=0; i<row; i++){
        int temp[col] = {0};
        for(int j=i; j<row; j++){
            temp[0] += ara[j][0]; /// Kadane's Algo (Contiguous sum) start
            tmpMx = tmp = temp[0];
            for(int k=1; k<col; k++){
                temp[k] += ara[j][k];
                tmp = max(temp[k], tmp+temp[k]);
                tmpMx = max(tmpMx, tmp);
            }
            maxRet = max(maxRet, tmpMx); /// Kadane's Algo ends here
        }
    }
    return maxRet;
}

int main()
{
    cout<<max2D()<<endl;
    return 0;
}
