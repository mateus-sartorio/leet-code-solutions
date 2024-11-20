// 11. Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;

        int j = height.size() - 1;

        int maxArea = 0;

        while(i < j) {
            cout << j << ", " << i << endl;
            int newArea = (j - i) * min(height[i], height[j]);
            
            if(newArea > maxArea) {
                maxArea = newArea;
            }

            if(height[i] >= height[j]) {
                j--;
            }
            else {
                i++;
            }
        }

        return maxArea;
    }
};
