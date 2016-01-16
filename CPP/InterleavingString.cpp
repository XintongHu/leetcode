class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l3 != l1 + l2) return false;
        vector<vector<bool> > v(l1 + 1, vector<bool>(l2 + 1, false));
        queue<pair<int, int> > q;
        pair<int, int> head;
        int x, y;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            head = q.front();
            q.pop();
            x = head.first, y = head.second;
            if (v[x][y]) continue;
            v[x][y] = true;
            if (x == l1 && y == l2) return true;
            if (x < s1.size() && s1[x] == s3[x + y]) q.push(make_pair(x + 1, y));
            if (y < s2.size() && s2[y] == s3[x + y]) q.push(make_pair(x, y + 1));
        }
        return false;
    }
};