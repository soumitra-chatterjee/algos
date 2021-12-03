// Find the root(s) of MHTs of a given tree (consisting 
// of N nodes, each node with a label from '0' to'N-1'

vector<int> FindRootsOfMHT(int n, vector<pair<int>> edges) {
        if(n == 1) {
            return {0};
        }
        vector<int> adj[n];
        vector<int> degree(n);
        for(vector<int> e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        for(int x = 0; x < n; x++) {
            if(degree[x] == 1) {
                q.push(x);
            }
        }
        while(n > 2) {
            int k = q.size();
            n -= k;
            for(int i = 0; i < k ; i++) {
                int curr = q.front();
                q.pop();
                for(int next : adj[curr]) {
                    if(--degree[next] == 1) {
                        q.push(next);
                    }
                }
            }
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
