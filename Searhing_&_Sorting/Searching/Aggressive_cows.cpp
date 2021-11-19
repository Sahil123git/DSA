#include <iostream>
#include <algorithm>

using namespace std; //we need to find the max diff b/w the cows
bool can_place_cow(int stalls[], int cows, int n, int mid)
{ //here we are assuming mid as gap which we need to maintain b/w cows
    int last_cow = stalls[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_cow >= mid)
        {
            last_cow = stalls[i];
            count++;
            // cout << "yes" << count << " " << mid << " " << (stalls[i]) << endl;
            if (count == cows)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int stalls, cows;
        cin >> stalls >> cows;
        int posn[stalls];
        for (int i = 0; i < stalls; i++)
        {
            cin >> posn[i];
        }
        sort(posn, posn + stalls);
        // for (int i = 0; i < stalls; i++)
        // {
        //     cout << posn[i] << " ";
        // }
        int low, high, ans = 0;
        low = 1;                           //here we want the start pt only
        high = posn[stalls - 1] - posn[0]; //we can keep high this or (1e9)  <---------
                                           //becuase we only want the largest dist
        while (low <= high)
        {
            int mid = (low + high) / 2;
            bool place = can_place_cow(posn, cows, stalls, mid);
            if (place)
            {
                ans = mid;
                low = mid + 1;
                // cout << high << " " << mid << endl;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans;
    }
    return 0;
}