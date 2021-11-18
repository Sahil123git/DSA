#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> setB(n + 1);
    setB[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        setB[i] = setB[i / 2] + (i % 2);
    }
    for (auto it : setB)
    {
        cout << it << " ";
    }
}/*https://youtu.be/l66WRC6x9Xk?list=PL-Mj6qSxHpa_fw8HFdGp88LNvgfzftkxj&t=1206*/