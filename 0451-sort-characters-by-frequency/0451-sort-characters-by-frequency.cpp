class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
       priority_queue<pair<int,char>>pq;
       
        for(char c:s){
            mpp[c]++;
        }
       for(const auto &ch:mpp){
           pq.push({ch.second,ch.first});
       }
       s.clear();
       while(!pq.empty()){
        pair<int,char>Top=pq.top();
        pq.pop();
        int freq=Top.first;
        char character=Top.second;
        while(freq--){
            s+=character;
        }
    }
       return s;

    }
};