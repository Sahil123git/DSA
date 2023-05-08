bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    if (p1.second > p2.second)
        return 1; // means no swap
    else
        return 0;
}

string reorganizeString(string s)
{
    int n = s.size();
    unordered_map<char, int> ump;
    for (auto &it : s)
    {
        ump[it]++;
    }

    vector<pair<char, int>> vp;
    for (auto &it : ump)
    {
        vp.push_back({it.first, it.second});
    }
    sort(vp.begin(), vp.end(), cmp);

    if (vp[0].second > (n + 1) / 2)
    { // if any char freq is greater than (n + 1)/ 2 then we can make string
        return "";
    }

    string str = s;
    int ind = 0;

    for (int i = 0; i < n; i += 2)
    { // first filling even posn becoz they will be either greater or equals to odd len
        if (vp[ind].second > 0)
        { // if freq of any char is ended
            str[i] = vp[ind].first;
        }
        else
        {
            ind++;
            str[i] = vp[ind].first;
        }
        vp[ind].second--;
    }

    for (int i = 1; i < n; i += 2)
    { // now filling rest of the remaining odd posn
        if (vp[ind].second > 0)
        {
            str[i] = vp[ind].first;
        }
        else
        {
            ind++;
            str[i] = vp[ind].first;
        }
        vp[ind].second--;
    }

    return str;
}