class Solution {
public:
    pair<int,int> dfs(vector<vector<int>> &adj, vector<int> &amt, int cur, int pre, int curH, int bob,int &high) {
        int isBob = -1, ans = INT_MIN;
        pair<int,int> p;
        for(int i = 0; i < adj[cur].size(); i++) {
            if(adj[cur][i] != pre) {
                p = dfs(adj, amt, adj[cur][i], cur, curH + 1, bob, high);
                isBob = max(isBob, p.second);
                ans = max(ans, p.first);
            }
        }
        if(ans == INT_MIN) 
            ans = 0;
        if(cur == bob) {
            high = curH;
            isBob = (curH + 1) / 2;
        }
        if(isBob == -1) return {ans + amt[cur], -1};
        if(isBob == 0) {
            ans += high % 2 == 0 ? (amt[cur] / 2) : amt[cur];
            return {ans, -1};
        }
        return {ans, isBob - 1};
    }
    int mostProfitablePath(vector<vector<int>>& ed, int bob, vector<int>& amount) {
        int n = ed.size() + 1,height = 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++) {
            adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
        }
        return dfs(adj, amount, 0, -1, 0, bob, height).first;
    }
};
