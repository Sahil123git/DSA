bool cmp(Job b, Job c)
{
    return b.profit > c.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    int max_ind = arr[0].dead;
    for (int i = 0; i < n; i++)
    {
        max_ind = max(arr[i].dead, max_ind);
    }
    vector<int> profits(max_ind + 1, -1);

    sort(arr, arr + n, cmp); // sort acc to max profit
    int max_proc = 0, cnt_jbs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        { // try to choose the max deadline for any process
            if (profits[j] == -1)
            { // if occupied then try lesser one
                profits[j] = 1;
                cnt_jbs += 1;
                max_proc += arr[i].profit;
                break;
            }
        }
    }
    return {cnt_jbs, max_proc};
}