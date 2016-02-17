class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int start = lower - 1;
        vector<string> ans;
        nums.push_back(upper + 1);
        for (int i = 0; i < nums.size(); ++i) {
            start++;
            if (nums[i] != start) {
                if (nums[i] == start + 1) ans.push_back(to_string(start));
                else ans.push_back(to_string(start) + "->" + to_string(nums[i] - 1));
                start = nums[i];
            }
        }
        return ans;
    }
};