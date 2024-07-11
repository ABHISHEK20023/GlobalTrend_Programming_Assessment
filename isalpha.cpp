#include <iostream>
#include <string>
using namespace std;

bool isAlphabeticChar(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isAlphabetic(std::string s)
{
    for (char c : s)
    {
        if (!isAlphabeticChar(c))
            return false;
    }
    return true;
}

int main()
{

    string s = "HelloWorld";
    cout << "Is alphabetic: " << boolalpha << isAlphabetic(s) << endl;
    return 0;
}
