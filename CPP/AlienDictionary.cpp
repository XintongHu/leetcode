class Solution {
public:
    string alienOrder(vector<string>& words) {
        int i = 0, j, n = words.size();
        int c1, c2;
        t = 0;
        string::iterator iter1, iter2;
        vector<int> ans;
        vector<bool> alpha(26, false);
        finish = vector<int>(26, -1);
        visit = vector<int>(26, 0);
        for(i = 0; i < n - 1; ++i) {
            for (char ch : words[i]) alpha[ch - 'a'] = true;
            iter1 = words[i].begin();
            iter2 = words[i + 1].begin();
            while (iter1 != words[i].end() && iter2 != words[i + 1].end() && *iter1 == *iter2) iter1++, iter2++;
            if (iter1 == words[i].end() || iter2 == words[i + 1].end()) continue;
            // c2 > c1
            c1 = *iter1 - 'a';
            c2 = *iter2 - 'a';
            map[c2].push_back(c1);
        }
        for (char ch : words[n - 1]) alpha[ch - 'a'] = true;
        for (i = 0; i < 26; ++i) {
            if (alpha[i]) {
                ans.push_back(i);
                if (visit[i] == 0) {
                    if (!dfs(i)) return "";
                }
            }
        }
        sort(ans.begin(), ans.end(), [&](const int a, const int b){
            return finish[a] < finish[b];
        });
        string ret = "";
        for (int item : ans) ret += (item + 'a');
        return ret;
    }
private:
    unordered_map<int, vector<int> > map;
    vector<int> finish;
    vector<int> visit;
    int t;
    
    bool dfs(int i) {
        visit[i] = -1;
        for (int item : map[i]) {
            if (visit[item] == 0) {if (!dfs(item)) return false;}
            else if (visit[item] == -1) return false;
        }
        finish[i] = t++;
        visit[i] = 1;
        return true;
    }
    
};