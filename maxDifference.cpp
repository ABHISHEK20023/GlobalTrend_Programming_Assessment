#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumDifference(vector<int> &nums)
{
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    return maxVal - minVal;
}

int main()
{
    vector<int> nums = {2, 3, 10, 6, 4, 8, 1};
    cout << "Maximum difference: " << maximumDifference(nums) << std::endl;
    return 0;
}
