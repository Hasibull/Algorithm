#include <bits/stdc++.h>
using namespace std;

int row, col;
int ara[100][100];

int max2D()
{
    int maxSubRect = INT_MIN;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            for(int k=i; k<row; k++)
                for(int l=j; l<col; l++){
                    int subRec = ara[k][l];
                    if(i) subRec -= ara[i-1][l];
                    if(j) subRec -= ara[k][j-1];
                    if(i && j) subRec += ara[i-1][j-1];
                    maxSubRect = max(maxSubRect, subRec);
                }

    return maxSubRect;
}

int main()
{
    /// freopen("input.txt", "r", stdin);

    cin>>row>>col;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            cin>>ara[i][j];
            if(i) ara[i][j] += ara[i-1][j];
            if(j) ara[i][j] += ara[i][j-1];
            if(i && j) ara[i][j] -= ara[i-1][j-1];
        }

    cout<<max2D()<<endl;
    return 0;
}
