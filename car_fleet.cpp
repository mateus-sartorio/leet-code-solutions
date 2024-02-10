// 853. Car Fleet
// Link: https://leetcode.com/problems/car-fleet/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> position_time;

        for (int i = 0; i < position.size(); i++)
        {
            position_time.push_back(pair(position[i], speed[i]));
        }

        sort(position_time.begin(), position_time.end(), [](const pair<int, int> &e1, const pair<int, int> &e2)
             { return e1.first > e2.first; });

        pair<int, int> &last = position_time[0];
        int count = 1;
        for (auto &element : position_time)
        {
            long left_side = (long)target * element.second - (long)last.first * element.second;
            long right_side = (long)target * last.second - (long)element.first * last.second;
            if (left_side < right_side)
            {
                count++;
                last = element;
            }
        }

        return count;
    }
};
