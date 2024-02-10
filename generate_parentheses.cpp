// 22. Generate Parentheses
// Link: https://leetcode.com/problems/generate-parentheses

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rec(vector<string> &result, string current_sequence, char new_parentheses, int opening_parentheses, int closing_parenthesis, int height, int n)
    {
        current_sequence += new_parentheses;

        if (new_parentheses == '(')
        {
            opening_parentheses++;
            height++;
        }
        else
        {
            closing_parenthesis++;
            height++;
        }

        if (opening_parentheses < closing_parenthesis)
        {
            return;
        }

        if (height == 2 * n)
        {
            if (opening_parentheses == closing_parenthesis)
            {
                result.push_back(current_sequence);
            }

            return;
        }
        else
        {
            if (opening_parentheses < n)
            {
                rec(result, current_sequence, '(', opening_parentheses, closing_parenthesis, height, n);
            }

            if (closing_parenthesis < opening_parentheses)
            {
                rec(result, current_sequence, ')', opening_parentheses, closing_parenthesis, height, n);
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        rec(result, "", '(', 0, 0, 0, n);
        rec(result, "", ')', 0, 0, 0, n);

        return result;
    }
};
