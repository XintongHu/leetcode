class Solution {
public:
    void helper(int x, int n, int k, vector<int>& c, vector<vector<int> >& ans) {
        c.push_back(x);
        if (c.size() == k) ans.push_back(c);
        else for (int i = x + 1; i <= n; ++i) helper(i, n, k, c, ans);
        c.pop_back();
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> c;
        for (int i = 1; i <= n; ++i) {helper(i, n, k, c, ans);}
        return ans;
    }
};