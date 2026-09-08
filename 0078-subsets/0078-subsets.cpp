class Solution {
public:
    void findsubsets(int ind, vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        findsubsets(ind+1, nums, ans, ds);//take case
        ds.pop_back();
        findsubsets(ind+1, nums, ans, ds);//don't take case
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        findsubsets(0, nums, ans, ds);
        return ans;
    }
};