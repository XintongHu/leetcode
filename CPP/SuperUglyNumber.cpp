class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        struct Comp
        {
           bool operator()(const pair<int, int>& s1, const pair<int, int>& s2)
           {
               return s1.first > s2.first;
           }
        };
        vector<pair<int, int> > h;
        unordered_map<int, int> index;
        vector<int> ans;
        int cnt = 1, i, sz = primes.size(), m, j;
        ans.push_back(1);
        for (int j : primes) {
            h.push_back(make_pair(j * ans[index[j]], j));
            //cout<<"push "<<j * ans[index[j]]<<","<<j<<" ";
            push_heap(h.begin(), h.end(), Comp());
        }
        while (cnt < n) {
            pop_heap(h.begin(), h.end(), Comp());
            m = h.back().first;
            ans.push_back(m);
            while (h.back().first == m) {
                j = h.back().second;
                index[j]++;
                //cout<<"pop "<<m<<","<<h.back().second<<" ";
                h.back().first = j * ans[index[j]];
                //cout<<"push "<<m<<","<<h.back().second<<" ";
                push_heap(h.begin(), h.end(), Comp());
                pop_heap(h.begin(), h.end(), Comp());
            }
            push_heap(h.begin(), h.end(), Comp());
            cnt++;
        }
        //for (auto k : ans) cout<<k<<endl;
        return ans.back();
    }
};
