#include <bits/stdc++.h>
using namespace std;

int row, col;
int ara[100][100];
int val[100][100];

struct max2DGrid
{
    int rowx, rowy;
    int colx, coly;
    int value;
};

max2DGrid max2D()
{
    int maxSubRect = INT_MIN;
    struct max2DGrid grid;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            for(int k=i; k<row; k++)
                for(int l=j; l<col; l++){
                    int subRec = ara[k][l];
                    if(i) subRec -= ara[i-1][l];
                    if(j) subRec -= ara[k][j-1];
                    if(i && j) subRec += ara[i-1][j-1];
                    if(subRec > maxSubRect){
                        maxSubRect = subRec;
                        grid.rowx = i, grid.rowy = k;
                        grid.colx = j, grid.coly = l;
                        grid.value = maxSubRect;
                    }
                }

    return grid;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin>>row>>col;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            cin>>ara[i][j]; val[i][j] = ara[i][j];
            if(i) ara[i][j] += ara[i-1][j];
            if(j) ara[i][j] += ara[i][j-1];
            if(i && j) ara[i][j] -= ara[i-1][j-1];
        }

    struct max2DGrid ans = max2D();
    cout<<"Value : "<<ans.value<<endl;
    for(int i=ans.rowx; i<=ans.rowy; i++){
        for(int j=ans.colx; j<=ans.coly; j++)
            cout<<setw(2)<<val[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

