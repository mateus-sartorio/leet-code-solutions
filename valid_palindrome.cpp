// 125. Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome

#include <iostream>
#include <cctype>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string processed_string = "";

        for (auto &c : s)
        {
            if (!isalnum(c))
            {
                continue;
            }

            processed_string += tolower(c);
        }

        string::iterator iter_begin = processed_string.begin();
        string::iterator iter_end = processed_string.end() - 1;

        while (iter_begin < iter_end)
        {
            if (*iter_begin != *iter_end)
            {
                return false;
            }

            iter_begin++;
            iter_end--;
        }

        return true;
    }
};