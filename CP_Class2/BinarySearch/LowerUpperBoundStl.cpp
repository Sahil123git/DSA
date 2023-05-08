// lower_bound and upper_bound in vector

#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector

using namespace std;

int main()
{
     int gfg[] = {1, 2, 2, 2, 3, 4, 5, 5};

     vector<int> v(gfg, gfg + 8); // 5 6 7 7 6 5 5 6

     sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7

     vector<int>::iterator lower, upper;
     // or auto lower = lower_bound(v.begin(), v.end(), 2);

     lower = lower_bound(v.begin(), v.end(), 2); // lower bound gives 1st occ ind
     upper = upper_bound(v.begin(), v.end(), 2); // and upper bound gives 1st greater val ind

     cout << "lower_bound for 2 at position "
          << (lower - v.begin()) << '\n';
     cout << "upper_bound for 2 at position "
          << (upper - v.begin()) << '\n';

     return 0;
}
