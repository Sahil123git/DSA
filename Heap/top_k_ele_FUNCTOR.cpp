#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Person
{
public:
    string name;
    int age;
    Person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
};
class Person_Comp
{
public:
    bool operator()(Person A, Person B)
    {
        return A.age < B.age; //if A'age is smaller than B'age then only swap
    }
};
int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<Person>, Person_Comp> k_comp; //filling values in Priority queue
    while (n > 0)
    {
        int age;
        string name;
        cin >> age >> name;

        Person p(age, name);
        k_comp.push(p);
        n--;
    }
    for (int i = 0; i < 3; i++)
    {
        Person p = k_comp.top();
        cout << p.name << " ";
        k_comp.pop();
    }
}