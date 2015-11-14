class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j, trapAll = 0, mi, h, p1, p2;
        int n = height.size();
        if (n < 3) return 0;
        vector<int> min, peak;
        if (height[0] > height[1]) peak.push_back(0);
        for (i = 1; i < n - 1; ++i) {
            if ((height[i] > height[i - 1] && height[i] >= height[i + 1]) ||
                (height[i] >= height[i - 1] && height[i] > height[i + 1]))
                peak.push_back(i);
        }
        if (height[n - 1] > height[n - 2]) peak.push_back(n - 1);
        i = 0; n = peak.size();
        while (i < n - 1) {
            j = i + 1;
            h = height[peak[i]];
            mi = j;
            for (int k = j; k < n; ++k) {
                if (height[peak[k]] >= h) {mi = k; break;}
                if (height[peak[k]] >= height[peak[mi]]) mi = k;
            }
            height[peak[i]] < height[peak[mi]] ? h = height[peak[i]] : h = height[peak[mi]];
            for (int k = peak[i] + 1; k < peak[mi]; ++k) trapAll += max(0, h - height[k]);
            i = mi;
        }
        return trapAll;
    }
};