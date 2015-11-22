class Solution {
public:
    void DFS(int course, vector<unordered_set<int> > &graph, vector<int> &visit,
             int *schedule, int *t) {
        (*t)++;
        for (auto next = graph[course].begin(); next != graph[course].end(); ++next) {
            if (visit[*next] == 0) {
                visit[*next] = -1;
                DFS(*next, graph, visit, schedule, t);
                (*t)++;
                schedule[*next] = *t;
            }
        }
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        int *schedule = new int[numCourses];
        int numP = prerequisites.size();
        int t = 0, i;
        vector<unordered_set<int> > graph(numCourses);
        for (i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].first].insert(prerequisites[i].second);
        }
        for (i = 0; i < numCourses; ++i) {
            if (visit[i] == 0) {
                visit[i] = -1;
                DFS(i, graph, visit, schedule, &t);
                t++;
                schedule[i] = t;
                visit[i] = 1;
            }
        }
        for (i = 0;i < numP; ++i) {
            int fc = prerequisites[i].first, sc = prerequisites[i].second;
            if (schedule[fc] < schedule[sc]) return false;
        }
        return true;
    }
};