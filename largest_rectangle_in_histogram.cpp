// 84. Largest Rectangle in Histogram
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> areas;

        pair<int, int> current = {-1, 0};
        for (auto &height : heights)
        {
            if (current.first == -1)
            {
                current = {1, height};
            }
            else if (height > current.second || ((height * (current.first + 1)) < (current.first * current.second)))
            {
                areas.push(current);
                current = {1, height};
            }
            else
            {
                current = {current.first + 1, height};
            }
        }

        areas.push(current);

        int max_area = 0;
        pair<int, int> current_rectangle = {-1, 0};
        while (!areas.empty())
        {
            current = areas.top();
            areas.pop();

            cout << current.first << " : " << current.second << endl;
            cout << current_rectangle.first << ", " << current_rectangle.second << endl;

            if (current_rectangle.first == -1)
            {
                current_rectangle = current;
            }

            int new_area = min(current_rectangle.second, current.second) * (current_rectangle.first + current.first);
            if (new_area > (current_rectangle.first * current_rectangle.second))
            {
                current_rectangle = {current_rectangle.first + current.first, min(current_rectangle.second, current.second)};
                cout << current_rectangle.first << ", " << current_rectangle.second << endl;
                max_area = max(new_area, max_area);
            }
            else
            {
                current_rectangle = {-1, 0};
            }
        }

        return max_area;
    }
};
