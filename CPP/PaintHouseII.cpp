class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        int mp = 0, m2p = 0, mc = INT_MAX, m2c = INT_MAX;
        int mip = -1, mic = -1;
        vector<int> prev(k, 0);
        vector<int> cur(k, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (j != mip) cur[j] = costs[i][j] + mp;
                else cur[j] = costs[i][j] + m2p;
                if (mc == INT_MAX) mc = cur[j], mic = j;
                else if (cur[j] < mc) m2c = mc, mc = cur[j], mic = j;
                else if (cur[j] < m2c) m2c = cur[j];
            }
            mp = mc, m2p = m2c;
            mip = mic;
            mc = m2c = INT_MAX;
            cur.swap(prev);
        }
        return mp;
    }
};