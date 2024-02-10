#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded = "[";

        for (auto &str : strs)
        {
            encoded += "\"" + str + "\",";
        }

        encoded[encoded.length() - 1] = ']';

        cout << encoded << endl;

        return encoded;
    }

    vector<string> decode(string s)
    {
    }
};