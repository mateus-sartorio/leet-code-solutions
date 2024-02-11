// 167. Two Sum II - Input Array Is Sorted
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int binary_search(vector<int> &numbers, int target, int begin, int end)
    {
        if (begin > end)
        {
            return -1;
        }

        int middle_index = (end + begin) / 2;
        int middle_element = numbers[middle_index];

        if (middle_element == target)
        {
            return middle_index;
        }
        else if (middle_element > target)
        {
            return binary_search(numbers, target, begin, middle_index - 1);
        }
        else
        {
            return binary_search(numbers, target, middle_index + 1, end);
        }
    }

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> output(2);

        for (int i = 0; i < numbers.size(); i++)
        {
            int result = binary_search(numbers, target - numbers[i], i + 1, numbers.size() - 1);

            if (result >= 0)
            {
                output[0] = i + 1;
                output[1] = result + 1;
                break;
            }
        }

        return output;
    }
};