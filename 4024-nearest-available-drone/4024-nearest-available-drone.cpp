class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=-1;
        int minimum=INT_MAX;
        for(int i=0;i<drones.size();i++){
            int md=abs(drones[i][0]-target[0])+abs(drones[i][1]- target[1]);
            if(md<=drones[i][2]){
                if(md<minimum){
                    minimum=md;
                    ans=i;
                }
            }
        }
        return ans;
    }
};