class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = (int)nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                int j = nums.size();
                while(nums[--j] <= nums[i - 1]);
                swap(nums[i - 1], nums[j]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};