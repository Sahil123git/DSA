#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_temp_arr(string pattern) // this is for making substring arr(prefix and suffix)
{
    vector<int> lps(pattern.length(), 0);
    int ind = 0;

    for (int i = 1; i < pattern.size();)
    {
        if (pattern[i] == pattern[ind]) // if char are equal
        {
            lps[i] = ind + 1;
            ind++;
            i++;
        }
        else
        {
            if (ind != 0) // go to prefix usng lps[ind-1]
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
        if (text[i] == pattern[j]) // if chars matched
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0) // if j is not equal to 0
            {
                j = lps[j - 1]; // then chk val in lps[j-1]
            }
            else
            {
                i++;
            }
        }
    }
    // cout << j << "end" << endl;
    if (j == pattern.length()) // if j iterated full pattern tht means we found our pattern in text
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
