class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        string result="";
        stack<char>st;
        for(int i=0;i<n;i++){
           if(st.empty()){
            st.push(s[i]);
            continue;
           }
           if(st.top()==s[i]){
            st.pop();
            continue;
           }
              st.push(s[i]);
        }
       while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};