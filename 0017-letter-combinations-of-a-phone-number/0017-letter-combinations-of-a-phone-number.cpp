class Solution {
public:
    vector<string>result;
    void solve(int ind, string digits, string temp, unordered_map<char, string>&mp){
        if(ind>=digits.length()){
            result.push_back(temp);
            return;
        }
        char ch=digits[ind];
        string str=mp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]); //do
            solve(ind+1, digits, temp, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
       
        string temp="";
        unordered_map<char, string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        solve(0,digits, temp, mp);
        return result;
    }
};