class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        string result="";
    for(int i=0;i<n;i++){
        while(!result.empty() && result.back()>num[i] && k>0){
            result.pop_back();
            k--;
        }
        if(!result.empty()|| num[i]!='0'){//to avoid the case in which preceding number is 0
            result.push_back(num[i]);
        }
    }    
        while(!result.empty() && k>0){
            result.pop_back();
            k--;
        }
        if(result.empty()){
            return "0";
        }
        return result;
    }
};