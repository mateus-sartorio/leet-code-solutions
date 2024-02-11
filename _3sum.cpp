// 15. 3Sum
// Link: https://leetcode.com/problems/3sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

class triplet
{
public:
    int v1, v2, v3;

    triplet(int v1, int v2, int v3) : v1(v1), v2(v2), v3(v3) {}

    bool operator==(const triplet &other) const
    {
        int arr1[] = {v1, v2, v3};
        int arr2[] = {other.v1, other.v2, other.v3};

        sort(arr1, arr1 + 3);
        sort(arr2, arr2 + 3);

        for (int i = 0; i < 3; i++)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator<(const triplet &other) const
    {
        return !(*this == other);
    }
};

class Solution
{
private:
    int binary_search(vector<pair<int, int>> &nums, pair<int, int> target, int begin, int end)
    {
        if (begin > end)
        {
            return -1;
        }

        int middle_index = (end + begin) / 2;
        pair<int, int> &middle_element = nums[middle_index];

        if (middle_element.first == target.first && middle_element.second >= target.second)
        {
            return middle_element.second;
        }
        else if (middle_element.first > target.first)
        {
            return binary_search(nums, target, begin, middle_index - 1);
        }
        else
        {
            return binary_search(nums, target, middle_index + 1, end);
        }
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<triplet> triplets;

        vector<pair<int, int>> ordered_nums;
        for (int i = 0; i < nums.size(); i++)
        {
            ordered_nums.push_back({nums[i], i});
        }

        sort(ordered_nums.begin(), ordered_nums.end(), [](const pair<int, int> &n1, const pair<int, int> &n2)
             { return n1.first < n2.first; });

        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int result = binary_search(ordered_nums, {-nums[i] - nums[j], j + 1}, 0, nums.size() - 1);
                cout << i << ", " << j << ", " << result << endl;
                if (result > j)
                {
                    cout << "entrou" << endl;
                    triplets.insert(triplet(nums[i], nums[j], nums[result]));
                }
            }
        }

        vector<vector<int>> output;
        cout << "======" << endl;
        for (auto &triplet : triplets)
        {
            cout << triplet.v1 << ", " << triplet.v2 << ", " << triplet.v3 << endl;
            output.push_back({triplet.v1, triplet.v2, triplet.v3});
        }

        return output;
    }
};
