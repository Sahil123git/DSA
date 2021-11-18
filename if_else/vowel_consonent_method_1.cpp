#include <iostream>
using namespace std;
int main()
{
    char alpha;
    cin >> alpha;
    if (alpha == 'i' || alpha == 'o' || alpha == 'a' || alpha == 'e' || alpha == 'u' || alpha == 'I' || alpha == 'O' || alpha == 'A' || alpha == 'E' || alpha == 'U')
    {
        printf("Vowel");
    }
    else
    {
        printf("Not Vowel");
    }

    return 0;
}