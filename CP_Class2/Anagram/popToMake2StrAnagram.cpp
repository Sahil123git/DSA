int remAnagram(string str1, string str2) // https://practice.geeksforgeeks.org/problems/anagram-of-string/1
{
    int LowerArr[26] = {0};
    for (int i = 0; i < str1.size(); i++)
    {
        LowerArr[str1[i] - 'a']++;
    }

    int cnt = 0;
    for (int i = 0; i < str2.size(); i++)
    {
        if (LowerArr[str2[i] - 'a'] > 0)
        {
            LowerArr[str2[i] - 'a']--;
        }
        else
        {
            cnt++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cnt += LowerArr[i];
    }
    return cnt;
}