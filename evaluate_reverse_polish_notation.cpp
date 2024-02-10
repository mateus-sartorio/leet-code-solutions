// 150. Evaluate Reverse Polish Notation
// Leet code problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> stack;

        for (auto &token : tokens)
        {
            if (!token.compare("+"))
            {
                int v1 = stack.top();
                stack.pop();
                int v2 = stack.top();
                stack.pop();
                int result = v2 + v1;
                stack.push(result);
            }
            else if (!token.compare("-"))
            {
                int v1 = stack.top();
                stack.pop();
                int v2 = stack.top();
                stack.pop();
                int result = v2 - v1;
                stack.push(result);
            }
            else if (!token.compare("*"))
            {
                int v1 = stack.top();
                stack.pop();
                int v2 = stack.top();
                stack.pop();
                int result = v2 * v1;
                stack.push(result);
            }
            else if (!token.compare("/"))
            {
                int v1 = stack.top();
                stack.pop();
                int v2 = stack.top();
                stack.pop();
                int result = v2 / v1;
                stack.push(result);
            }
            else
            {
                stack.push(stoi(token));
            }
        }

        return stack.top();
    }
};
