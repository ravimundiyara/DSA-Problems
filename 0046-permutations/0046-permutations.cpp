class Solution {
public:
    int n;
    vector<vector<int>>result;
   
    void solve(vector<int>& nums, vector<bool>&used,  vector<int>&current ){
        if(current.size()==nums.size()){
            result.push_back(current);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i]==true){
                continue;
            }
            current.push_back(nums[i]);
            used[i]=true;
            solve(nums, used, current);
            current.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
         vector<bool>used(n, false);
         vector<int>current;
        solve(nums, used, current);
        return result;
    }
};