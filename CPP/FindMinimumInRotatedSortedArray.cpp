class Solution {
public:
    int bs(vector<int>& nums, int p, int q) {
        if (p == q) return nums[p];
        else if (q - p == 1) return min(nums[p], nums[q]);
        else {
            int mid = (p + q)/2;
            if (nums[mid] <= nums[mid + 1] && nums[mid] <= nums[mid - 1]) return nums[mid];
            else if (nums[mid] < nums[0]) return bs(nums, p, mid - 1);
            else if (nums[mid] > nums[0]) return bs(nums, mid + 1, q);
        }
    }
    int findMin(vector<int>& nums) {
        if (nums[0] < nums.back()) return nums[0];
        return bs(nums, 0, nums.size() - 1);
    }
};