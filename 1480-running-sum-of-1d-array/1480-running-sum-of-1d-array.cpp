class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res(nums.size());
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            res[i] = currSum;
        }
        return res;
    }
};