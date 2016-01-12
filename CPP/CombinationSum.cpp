class Solution {
public:
    void helper(int ith, int sum, vector<int>& c, vector<int>& candidates, vector<vector<int> > &ans, int target) {
        int val = candidates[ith];
        c.push_back(val);
        sum += val;
        if (sum == target) ans.push_back(c);
        else if (sum < target) for (int i = ith; i < candidates.size(); ++i) helper(i, sum, c, candidates, ans, target);
        sum -= val;
        c.pop_back();
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> c;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) helper(i, 0, c, candidates, ans, target);
        return ans;
    }
};