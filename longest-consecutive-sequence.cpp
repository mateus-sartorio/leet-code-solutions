#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> did_key_appear;
        unordered_map<int, bool> sequence_leaders;

        for (const auto &n : nums)
        {
            did_key_appear[n] = true;

            if (!did_key_appear.contains(n - 1))
            {
                sequence_leaders[n] = true;
            }

            if (sequence_leaders.contains(n + 1))
            {
                sequence_leaders.erase(n + 1);
            }
        }

        int max_sequence = 0;
        for (const auto &pair : sequence_leaders)
        {
            int new_sequence = 1;
            while (did_key_appear.contains(pair.first + new_sequence))
            {
                new_sequence++;
            }

            if (new_sequence > max_sequence)
            {
                max_sequence = new_sequence;
            }
        }

        return max_sequence;
    }
};
