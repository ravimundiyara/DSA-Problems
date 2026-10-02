class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>s(nums.begin(), nums.end());
       
        for(int num:s){
        if(s.find(num-1)==s.end()){
            int count=1;  
        while(s.find(num+1)!=s.end()){
                num++;
                count++;
            }
            longest=max(longest, count);
        }
    }
        return longest;
    }
};