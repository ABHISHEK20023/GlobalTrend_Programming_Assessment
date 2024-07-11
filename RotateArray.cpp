#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(std::vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "Original Array : ";
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    rotate(nums, k);
    cout << "Array after rotating to right " << k << " times : ";
    for (auto i : nums)
        cout << i << " ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
