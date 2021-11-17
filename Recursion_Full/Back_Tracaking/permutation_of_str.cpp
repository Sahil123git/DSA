#include <iostream>
using namespace std;
void permu_str(string str, int i)
{
    if (str[i] == '\0')
    {
        cout << str << endl;
        return;
    }

    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        permu_str(str, i + 1);
        swap(str[i], str[j]);
    }

}
int main()
{
    string str;
    cin >> str;
    permu_str(str, 0);
    return 0;
}
