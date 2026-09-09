class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
    int currsum=0;
    int closestSum=nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size();i++){
            int left=i+1, right=nums.size()-1;
        while(left<right){
        currsum=nums[i]+ nums[left]+ nums[right];
        if (abs(currsum - target) < abs(closestSum - target)) {
            closestSum = currsum;
                }
        if(currsum < target){
            left++;
        }
        else if( currsum > target){
            right--;
        }
        else {
            return currsum;
        }
        }
        }
        return closestSum;
    }
};