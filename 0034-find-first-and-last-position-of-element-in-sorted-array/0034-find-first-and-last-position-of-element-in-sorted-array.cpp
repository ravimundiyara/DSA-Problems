class Solution {
public:
vector<int>vc;
int firstOccurrence(vector<int>& nums, int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
     high = mid - 1;
        } 
    }
    vc.push_back(ans);
    return -1;
   
}
int lastOccurrence(vector<int>& nums, int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            low=mid+1;}
     
     else if (nums[mid] < target) {
    low = mid + 1;
     }
    else {
    high = mid - 1;
    }
    }
     vc.push_back(ans);
     return -1;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        firstOccurrence(nums,target);
        lastOccurrence(nums,target);
        return vc;
    }
};