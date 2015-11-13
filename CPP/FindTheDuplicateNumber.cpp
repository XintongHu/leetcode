class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i, p, q, mid, cnt, s = nums.size();
        p = 1, q = s - 1, mid = (p + q)/2;
        while (p != q) {
            cnt = 0;
            for (i = 0; i < s; ++i) {
                if (nums[i] <= mid && nums[i] >= p) cnt++;
            }
            if (cnt > int((q - p + 1)/float(2) + 0.5)) q = mid;
            else p = mid + 1;
            mid = (p + q)/2;
        }
        return mid;
    }
};