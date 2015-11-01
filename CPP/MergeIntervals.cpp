/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compare(const Interval &a, const Interval &b) {
        if (a.start < b.start)
            return 1;
        else
            return 0;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        Interval tmp;
        if(intervals.empty() == 1)
            return ans;
        sort(intervals.begin(), intervals.end(), compare);
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > ans.back().end)
                ans.push_back(intervals[i]);
            else {
                tmp.start = ans.back().start;
                tmp.end = max(intervals[i].end, ans.back().end);
                ans.pop_back();
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};