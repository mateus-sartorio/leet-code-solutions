// 271. Encode and Decode Strings
// Link: https://leetcode.com/problems/encode-and-decode-strings/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded = "";

        for (auto &str : strs)
        {
            encoded += str + '\0';
        }

        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> decoded;
        stringstream stream(s);
        string substring;
        while (getline(stream, substring, '\0'))
        {
            decoded.push_back(substring);
        }

        for (auto &st : decoded)
        {
            cout << st << endl;
        }

        return decoded;
    }
};
