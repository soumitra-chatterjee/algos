// Given a Circular Array , find the next greater
// element for each element (LC - 503)

vector<int> nextGreaterElements(vector<int>& a) {
        stack<pair<int, int>> stk;     // stack >>> {val, index} 
        unordered_map<int, int> mp;    // index -> res
        vector<int> ans;
        int n = a.size();
        for(int x: {0, 1}) {
            for(int i = 0; i < n; i++) {
                int val = a[i];
                while(stk.size() and stk.top().first < val) {
                    mp[stk.top().second] = val;
                    stk.pop();
                }
                
                stk.push({val, i});
                
            }
        }
        for(int x = 0; x < n ; x++) {
            if(mp.count(x)) {
                ans.push_back(mp[x]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
