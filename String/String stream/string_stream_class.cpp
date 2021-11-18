#include <iostream>
#include <sstream>
using namespace std;
class student
{
public:
    int age, standard;
    string str1, str2;

    void set_age(int age)
    {
        this->age = age;
    }
    void set_first_name(string str_name)
    {
        str1 = str_name;
    }
    void set_last_name(string str_lastname)
    {
        str2 = str_lastname;
    }
    void set_standard(int standard)
    {
        this->standard = standard;
    }

    string display() //this should be string return type
    {
        stringstream ss;
        ss << age << "," << str1 << "," << str2 << "," << standard;
        return ss.str(); //we need to return this print
    }
};

int main()
{
    int age, standard;
    string str_name, str_lastname;
    cin >> age >> str_name >> str_lastname >> standard;

    student s1;
    s1.set_age(age);
    s1.set_first_name(str_name);
    s1.set_last_name(str_lastname);
    s1.set_standard(standard);

    cout << s1.display();
    return 0;
}
