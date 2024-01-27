// 22. Generate Parentheses
// Leet code link: https://leetcode.com/problems/generate-parentheses/description/

#include <vector>
#include <stack>
#include <cmath>
#include <bitset>
#include <iostream>

class Solution {
public:

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;

        for(int i = 0; i < pow(2, 2*n); i++) {
            std::stack<char> stack;
            std::string s = std::bitset<16>(i).to_string().substr(16 - 2*n, 2*n);

            bool is_combination_valid = true;
            for(auto& c : s) {
                if(c == '0') {
                    c = '(';
                    stack.push('(');
                }
                else if(c == '1') {
                    c = ')';

                    if(stack.empty()) {
                       is_combination_valid = false;
                       break;
                    }

                    stack.pop();
                }
            }

            if(is_combination_valid && stack.empty()) {
                result.push_back(s);
            }
        }

        return result;
    }
};
