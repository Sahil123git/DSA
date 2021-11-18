#include <iostream>
using namespace std;
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int arr1[n1][n2], arr2[n2][n3];
    int ans[n1][n3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k < n2; k++) //smaller than n2 because n2 is same for both matrices
            {
                ans[i][j] += arr1[i][k] * arr2[k][j]; //arr1[i][k] 1st block contain i because this will remain same for both (k and j)
                //after their ending i will increment by 1. 2nd block contains k because this has to chng every time
            } //arr2[k][j] 1st blocks contain k because k will change everytime but 2nd block will contain j because it will chnge after k cmplts
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}