class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int base = 1;
        ans.push_back(0);
        for (int i = 1; i <= n; ++i) {
            for (int j = base - 1; j >= 0; --j) {
                ans.push_back(ans[j] + base);
            }
            base *= 2;
        }
        return ans;
    }
};