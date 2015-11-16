class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> strNums;
        int size = nums.size();
        for (int i = 0; i < size; ++i) strNums.push_back(to_string(nums[i]));
        struct {
            bool operator()(string a, string b)
            {
                if (a[0] != b[0]) return a < b;
                else {
                    int j = 0;
                    while (j < a.size() && a[j] == b[j]) j++;
                    if (a[j] == '\0') return operator()(a, b.substr(j, b.size() - j));
                    else if (b[j] == '\0') return operator()(a.substr(j, a.size() - j), b);
                    else return a < b;
                }
            }
        } customLess;
        sort(strNums.begin(), strNums.end(), customLess);
        int j = 0;
        for (int i = size - 1; i >= j; --i) ans += strNums[i];
        if (ans[0] == '0') return "0";
        return ans;
    }
};