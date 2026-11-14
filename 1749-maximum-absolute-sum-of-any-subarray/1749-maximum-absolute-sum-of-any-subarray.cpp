class Solution {
public:
    int maxsumsubarray(vector<int>& nums) {
          int currsum=0, maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            maxsum=max(currsum, maxsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
    int minsumsubarray(vector<int>& nums) {
          int currsum=0, minsum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            minsum=min(currsum, minsum);
            if(currsum>0){
                currsum=0;
            }
        }
        return minsum;
    }

    int maxAbsoluteSum(vector<int>& nums){
        int maxi=maxsumsubarray(nums);
        int mini=minsumsubarray(nums);
    int result=max(maxi, abs(mini));
    return result;
   }
};