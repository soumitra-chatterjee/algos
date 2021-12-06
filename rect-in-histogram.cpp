// Find the Largest Rectangle in a Histogram. (LC-84)

int rectInHistogram() {
	a.push_back(0);   // edge case handelling
        int N = a.size();
        int x = 0, res = 0;
        
        stack<int> stk;     // contains indices for heights
        
        while(x < N) {
            if(stk.empty() or a[x] >= a[stk.top()]) {
                stk.push(x++);
            }
            else {
                int curr = stk.top();
                stk.pop();
                int curr_area = a[curr] * (stk.empty() ? x : x - stk.top() - 1);
                res = max(res, curr_area);
            }
        }
        
        return res;
}
