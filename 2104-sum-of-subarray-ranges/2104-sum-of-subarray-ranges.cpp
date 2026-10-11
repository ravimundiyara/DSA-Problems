class Solution {
public:
    // previous smaller element
  vector<int>getNSL(vector<int>&nums, int n){
            vector<int>result(n);
            stack<int>st;
            for(int i=0;i<n;i++){
                if(st.empty()){
                    result[i]=-1;
                }else{
                    while(!st.empty() && nums[st.top()]>nums[i]){
                        st.pop();
                    }
                    result[i]=st.empty()? -1: st.top();
                }
                st.push(i);
            }
            return result;
    }
    //Next smaller element
     vector<int>getNSR(vector<int>&nums, int n){
            vector<int>result(n);
            stack<int>st;
            for(int i=n-1;i>=0;i--){
                if(st.empty()){
                    result[i]=n;
                }else{
                    while(!st.empty() && nums[st.top()]>=nums[i]){
                        st.pop();
                    }
                    result[i]=st.empty()? n: st.top();
                }
                st.push(i);
            }
            return result;
    }

    // Previous Greater Element
    vector<int> getNGL(vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }
    //next greater element
     vector<int> getNGR(vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
         int n=nums.size();
       vector<int>NSL=getNSL(nums,n);
       vector<int>NSR=getNSR(nums,n);
       vector<int> NGL = getNGL(nums, n);
       vector<int> NGR = getNGR(nums, n);
        long long sumMin = 0;
        long long sumMax = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - NSL[i];
            long long rightMin = NSR[i] - i;

            long long leftMax = i - NGL[i];
            long long rightMax = NGR[i] - i;

            sumMin += 1LL * nums[i] * leftMin * rightMin;
            sumMax += 1LL * nums[i] * leftMax * rightMax;
        }

        return sumMax - sumMin;
    }
};