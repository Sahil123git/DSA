#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[100] = "what is     your name My name      is sahil dussa";
    char *ptr = strtok(str, " "); //this will extract 1st string
    cout << ptr << " ";

    while (ptr != NULL)
    {
        ptr = strtok(NULL, " "); //this will extract all strings till NULL
        cout << ptr << " ";
    }
}