class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        indegree = vector<int> (numCourses, 0);
        for (auto& it : prerequisites) {
            addedge(it[0], it[1]);
            indegree[it[0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) que.push(i);
        } 
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            for (auto& it : graph[tmp]) {
                indegree[it]--;
                if(indegree[it] == 0) que.push(it);
            }
        }
        for (auto& it : indegree) {
            if(it != 0) return false;
        }
        return true;
    }
    void addedge(int a, int b) {
        graph[b].push_back(a);
    }
    vector<vector<int>>graph;
    vector<int> indegree;
};