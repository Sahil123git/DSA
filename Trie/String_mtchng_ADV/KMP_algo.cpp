#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_temp_arr(string pattern) // this is for making substring arr(prefix and suffix)
{
    vector<int> lps(pattern.length(), 0);
    int ind = 0;

    for (int i = 1; i < pattern.size();)
    {
        if (pattern[i] == pattern[ind])
        {
            lps[i] = ind + 1;
            ind++;
            i++;
        }
        else
        {
            if (ind != 0)
            {
                ind = lps[ind - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP_search(string text, string pattern) // This is KMP algo
{
    vector<int> lps = compute_temp_arr(pattern);

    int i = 0, j = 0;
    while (i < text.length() && j < pattern.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    if (j == pattern.length())
    {
        return true;
    }
    return false;
}

int main()
{
    string str = "abcxabcdabcdabcy", subString = "abcdabcy";
    if (KMP_search(str, subString))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
}