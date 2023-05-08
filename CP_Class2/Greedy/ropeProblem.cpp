/*Combining ropes
find min cost to combine all ropes given is cost of combining ropes
4 3 2 1 9
cost = 7 + 16 + 18 + 19
cost = 6 + 9 + 18 + 19

find ropes with smallest combining cost

Bruteforce chk ans using recursion*/

bool mycmp(int a, int b)
{
    return a > b;
}

int main() // TC: n^2(log n)
{
    int ropes[] = {4, 3, 2, 1, 9};
    vector<int> v(ropes);
    int total = 0;

    while (v.size() > 1)
    {
        sort(v.begin(), v.end(), mycmp);
        int newsize = v[v.size() - 1] + v[v.size() - 2]; // newsize will become new ele
        total = total + newsize;
        v.pop_back();
        v.pop_back();
        v.push_back(newsize); // now insert new ele
    }
    cout << total << endl;
}
