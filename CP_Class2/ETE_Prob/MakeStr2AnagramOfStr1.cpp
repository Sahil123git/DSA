int minSteps(string str1, string str2)
{
    unordered_map<char, int> ump;
    for (int i = 0; i < str1.size(); i++)
    {
        ump[str1[i]]++;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        ump[str2[i]] -= 1;
    }

    int cnt = 0;
    for (auto it : ump)
    {
        cnt += abs(it.second);
    }
    return cnt / 2;
} // https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/