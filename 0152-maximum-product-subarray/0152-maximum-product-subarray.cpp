class Solution {
public:
    int maxProduct(vector<int>& nums) {

       int maxend=nums[0];
       int minend=nums[0];
       int result=nums[0];
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=minend*nums[i];
            int v3=maxend*nums[i];
            maxend=max(v1, max(v2, v3));
            minend=min(v1, min(v2, v3));
            result=max(result, max(maxend, minend));
        }
        return result;
    }
};