// 217. Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_set<int> nums_set;

        for (auto &n : nums)
        {
            nums_set.insert(n);
        }

        return nums_set.size() != nums.size();
    }
};
