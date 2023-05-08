vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rowSt = 0, rowEnd = matrix.size() - 1, colst = 0, colEnd = matrix[0].size() - 1;

    vector<int> res;
    while (rowSt <= rowEnd && colst <= colEnd)
    {
        int ind = colst;
        while (ind <= colEnd)
        {
            res.push_back(matrix[rowSt][ind]);
            ind++;
        }
        rowSt++;

        ind = rowSt;
        while (ind <= rowEnd)
        {
            res.push_back(matrix[ind][colEnd]);
            ind++;
        }

        colEnd--;

        if (colst > colEnd || rowSt > rowEnd)
        {
            break;
        }
        ind = colEnd;
        while (ind >= colst)
        {
            res.push_back(matrix[rowEnd][ind]);
            ind--;
        }
        rowEnd--;

        ind = rowEnd;
        while (ind >= rowSt)
        {
            res.push_back(matrix[ind][colst]);
            ind--;
        }
        colst++;
    }
    return res;
}