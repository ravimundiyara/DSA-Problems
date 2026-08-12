class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = "";

        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            bool match=true;
            for(int j=1;j<strs.size();j++){
               if(strs[j].size()<i ||ch!=strs[j][i]){
                match=false;
                break;
               }
            }
            if(match==false){
                break;
            }else{
            prefix += ch;
            }
        }
        return prefix;
    }
};