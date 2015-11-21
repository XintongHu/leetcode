class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        int pos = 0, k = pattern.size(), i;
        for (i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                words.push_back(str.substr(pos, i - pos));
                pos = i + 1;
            }
        }
        words.push_back(str.substr(pos, i - pos));
        if (k != words.size()) return false;
        unordered_map<string, string> PtS, StP;
        for (i = 0; i < k; ++i) {
            string p = pattern.substr(i, 1);
            string s = words[i];
            if (PtS.find(p) == PtS.end() && StP.find(s) == StP.end()) {
                PtS[p] = s; StP[s] = p;
            }
            else if (PtS[p] == s && StP[s] == p);
            else return false;
        }
        return true;
    }
};