class Solution {
public:
    void DFS(int course, vector<unordered_set<int> > &graph, vector<int> &visit, vector<int> &order) {
        for (auto next = graph[course].begin(); next != graph[course].end(); ++next) {
            if (visit[*next] == 0) {
                visit[*next] = -1;
                DFS(*next, graph, visit, order);
                order.push_back(*next);
                visit[*next] = 1;
            }
            else if (visit[*next] == -1) order.push_back(-1);
        }
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        vector<int> order;
        int numP = prerequisites.size();
        int i;
        vector<unordered_set<int> > graph(numCourses);
        for (i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].first].insert(prerequisites[i].second);
        }
        for (i = 0; i < numCourses; ++i) {
            if (visit[i] == 0) {
                visit[i] = -1;
                DFS(i, graph, visit, order);
                order.push_back(i);
                visit[i] = 1;
            }
        }
        bool flag = true;
        for (i = 0; i < order.size(); ++i) {
            if (order[i] == -1) {
                flag = false;
                break;
            }
        }
        if (!flag) order.clear();
        return order;
    }
};