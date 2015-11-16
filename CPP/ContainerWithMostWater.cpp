class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, wat, tmp;
        int p = 0, q = height.size() - 1;
        while (p < q) {
            wat = min(height[p], height[q]) * (q - p);
            if (wat > ans) ans = wat;
            if (height[p] < height[q]) {
                tmp = height[p];
                while (height[p] <= tmp) p++;
            }
            else {
                tmp = height[q];
                while (height[q] <= tmp) q--;
            }
        }
        return ans;
    }
};