/*
Given a string, find the length of the longest substring without repeating characters.
The function should return an integer representing the length of the longest substring without repeating characters.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int ans = 0;
    for (; j < s.size(); j++)
    {
        if (mp.count(s[j]) == 1 && mp[s[j]] >= i)
        {
            i = mp[s[j]] + 1;
        }
        mp[s[j]] = j;
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter string : ";
    cin >> str;
    int len = lengthOfLongestSubstring(str);
    cout << "length of longest substring without repeated characters : " << len << endl;
}