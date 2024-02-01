// 739. Daily Temperatures
// LeetCode link: https://leetcode.com/problems/daily-temperatures/

#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size(), 0);

        stack<pair<int, int>> stack;

        for(int i = 0; i < temperatures.size(); i++) {
            int temperature = temperatures[i];

            while(!stack.empty() && temperature > stack.top().first) {
                auto& top = stack.top();
                output[top.second] = i - top.second;
                stack.pop();
            }

            stack.push(pair(temperature, i));
        }
        
        return output;
    }
};
