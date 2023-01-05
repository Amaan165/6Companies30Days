class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(v[i] % v[j] == 0) dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(dp[i] == ans) {
                index = i;
                break;
            }
        }
        vector<int> res;
        int x = index;
        int a = ans;
        res.push_back(v[index]);
        for(int i = index - 1; i >= 0; i--) {
            if(dp[i] == a - 1 && v[x] % v[i] == 0) {
                res.push_back(v[i]);
                a--;
                x = i;
            }
        }
        return res;
    }
};
