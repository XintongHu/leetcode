class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       unordered_set<string> &wordList) {
        vector<vector<string> > ans, ansTmp;
        unordered_set<string> s1, s2, s3;
        s1.insert(beginWord);
        s2.insert(endWord);
        int i, j, w, width = beginWord.length();
        char ch;
        string str, tmp;
        bool endFlag = false;
        while (!s1.empty() && !s2.empty() && !endFlag) {
            for (auto item = s1.begin(); item != s1.end(); ++item) wordList.erase(*item);
            for (auto item = s1.begin(); item != s1.end(); ++item) {
                str = tmp = *item;
                for (i = 0; i < width; ++i) {
                    ch = str[i];
                    for (j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (wordList.find(str) != wordList.end()) {
                            s3.insert(str);
                            map[str].push_back(tmp);
                            if (s2.find(str) != s2.end()) endFlag = true;
                        }
                    }
                    str[i] = ch;
                }
            }
            s1.swap(s3);
            s1.swap(s2);
            s3.clear();
        }
        vector<string> ladder;
        for (auto item = s1.begin(); item != s1.end(); ++item) {
            if (s2.find(*item) != s2.end()) {
                ansTmp.clear();
                backTrack(*item, ansTmp, ladder);
                if (ansTmp.size() == 1) {reverse(ansTmp[0].begin(), ansTmp[0].end()); return ansTmp;}
                for (i = 0; i < ansTmp.size() - 1; ++i) {
                    for (j = i + 1; j < ansTmp.size(); ++j) {
                        if (ansTmp[i].back() == endWord && ansTmp[j].back() == beginWord) {
                            ans.push_back(vector<string>());
                            for (w = ansTmp[j].size() - 1; w > 0 ; --w) {
                                ans.back().push_back(ansTmp[j][w]);
                            }
                            for (w = 0; w < ansTmp[i].size(); ++w) {
                                ans.back().push_back(ansTmp[i][w]);
                            }
                        }
                        else if (ansTmp[j].back() == endWord && ansTmp[i].back() == beginWord){
                            ans.push_back(vector<string>());
                            for (w = ansTmp[i].size() - 1; w > 0 ; --w) {
                                ans.back().push_back(ansTmp[i][w]);
                            }
                            for (w = 0; w < ansTmp[j].size(); ++w) {
                                ans.back().push_back(ansTmp[j][w]);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
private:
    unordered_map<string, vector<string> > map;
    void backTrack(string step, vector<vector<string> > &tmp, vector<string> &ladder) {
        ladder.push_back(step);
        if (map[step].empty()) tmp.push_back(ladder);
        else {
            for (string p : map[step]) backTrack(p, tmp, ladder);
        }
        ladder.pop_back();
    }
};