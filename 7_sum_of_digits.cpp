#include <iostream>
using namespace std;

int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    int num = 12345;
    cout << "Sum of digits of " << num << " is " << sumOfDigits(num) << endl;
    return 0;
}
