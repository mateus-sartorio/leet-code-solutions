#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums_set;

        for(auto& n : nums) {
            nums_set.insert(n);
        }

        return nums_set.size() != nums.size();
    }
};
