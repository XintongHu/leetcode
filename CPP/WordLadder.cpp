class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> wordList) {
        int wsz = (*wordList.begin()).size(), i, j, qsz;
        unordered_set<string> q1;
        unordered_set<string> q2;
        q1.insert(beginWord);
        q2.insert(endWord);
        wordList.erase(endWord);
        wordList.erase(beginWord);
        int dist1 = 1, dist2 = 1;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                int tmp = dist1;
                dist1 = dist2;
                dist2 = tmp;
            }
            unordered_set<string> s;
            for (auto k = q1.begin(); k != q1.end(); k++) {
                string parent = *k;
                for (i = 0; i < wsz; ++i) {
                    char tmp = parent[i];
                    for (j = 0; j < 26; ++j) {
                        parent[i] = 'a' + j;
                        if (q2.find(parent) != q2.end()) return dist1 + dist2;
                        if (wordList.find(parent) != wordList.end()) {
                            s.insert(parent);
                            wordList.erase(parent);
                        }
                    }
                    parent[i] = tmp;
                }
            }
            swap(q1, s);
            dist1++;
        }
        return 0;
    }
};