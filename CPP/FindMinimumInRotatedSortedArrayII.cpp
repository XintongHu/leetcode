class Solution {
public:
    int findMin(vector<int>& nums) {
        int l, r, mid;
        l = 0, r = nums.size() - 1;
        if (nums.empty()) return -1;
        while (l < r) {
            mid = (l + r)/2;
            if (nums[l] < nums[r]) return nums[l];
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else {
                if (nums[mid] == nums[l]) l++, r--;
                else if (nums[mid] > nums[l]) r = mid - 1;
                else if (nums[mid] < nums[l]) r = mid;
            }
        }
        return nums[l];
    }
};