#include <iostream> //Time complexity is O[n]
#include <stack>
using namespace std;

void stock_span(int prices[], int n, int span[])
{
    stack<int> s; //this will hold all the correct addresses of prices arr
    s.push(0);
    span[0] = 1; //this span will hold all the correct stock spans
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && prices[s.top()] <= prices[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            int prev_high = s.top();
            span[i] = i - prev_high;
        }
        s.push(i);
    }
}
int main()
{
    int prices[] = {100, 40, 30, 20, 60, 75, 85, 90};
    int n = sizeof(prices) / sizeof(int);
    int span[10000] = {0};

    stock_span(prices, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    return 0;
}