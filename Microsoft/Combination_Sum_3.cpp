class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        helper(combination, 0, k, n, 0);
        return ans;
    }
    
    void helper(vector<int>& combi, int sum, int k, int n, int num){
        if(combi.size() >k || sum > n) return;
        
        if(combi.size() == k && sum == n)
            ans.push_back(combi);
        
        for(int i = num + 1; i <= 9; i++){
            combi.push_back(i);
            helper(combi, sum + i, k, n, ++num);
            combi.pop_back();
        }
    }
};
