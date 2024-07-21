class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            for (int e : adj[ele]) {
                indegree[e]--;
                if (indegree[e] == 0) {
                    q.push(e);
                }
            }
            topo.push_back(ele);
        }

        if (topo.size() != numCourses) {
            return false;
        }
        return true;
    }
};