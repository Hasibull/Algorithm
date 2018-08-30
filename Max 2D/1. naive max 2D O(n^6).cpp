#include <bits/stdc++.h>
using namespace std;

const int row = 4, col = 4;
int ara[row][col] = {
    { 0, -2, -7,  0},
    { 9,  2, -6,  2},
    {-4,  1, -4,  1},
    {-1,  8,  0, -2}
};

int max2D()
{
    int maxSubRec = INT_MIN;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            for(int k=i; k<row; k++)
                for(int l=j; l<col; l++){
                    int subRec = 0;
                    for(int a=i; a<=k; a++)
                        for(int b=j; b<=l; b++)
                            subRec += ara[a][b];
                    maxSubRec = max(maxSubRec, subRec);
                }

    return maxSubRec;
}

int main()
{
    cout<<max2D()<<endl;
    return 0;
}
