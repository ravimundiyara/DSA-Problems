class Solution {
public:

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& temp, vector<vector<int>>& ans) {

        // Target reached
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // No more candidates or target becomes negative
        if (index == candidates.size() || target < 0) {
            return;
        }

        // Choice 1: Take current element
        temp.push_back(candidates[index]);

        // Stay at same index because we can reuse the element
        solve(candidates, target - candidates[index],
              index, temp, ans);

        temp.pop_back();

        // Choice 2: Don't take current element
        solve(candidates, target, index + 1,
              temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};