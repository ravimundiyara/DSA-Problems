class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(st.empty()){ //agr stack mai kuch bhi nhi pada h to 
                st.push({c,1});
                continue;
            }
            if(st.top().first!=c){ //agr stack mai jo top pe h vo string ke new character se match nhi ho rha tab uss 
                st.push({c,1}); //character ko push kr denge
                continue;
            }
            if( st.top().second<(k-1) ){ //agr mera top pe jo character pda h uska count k-1 se chota h tab count bdaha deng
                pair<char, int> p= st.top();
                st.pop();
                st.push({p.first, p.second+1});
                continue;
            }
            st.pop(); //agr mera count k-1 ho chuka h or next character vo top ke equal h tab k times pop kr denge;
        }

        string res="";
        while(!st.empty()){
            pair<char,int>p=st.top();
            st.pop();
            while(p.second--){
                res.push_back(p.first);
            }
        }
        reverse(res.begin(), res.end()); //reverse order mai nikla tha stack se isliye reverse krna pda
           return res; 
        
    }
};