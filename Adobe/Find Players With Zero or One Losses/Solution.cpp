class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost;
        unordered_map<int,int>win;
        int n=matches.size();
        for(int i=0;i<n;i++){
            win[matches[i][0]]++;
            lost[matches[i][1]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>temp2;
        for(auto it:win){
            if(lost.find(it.first)==lost.end()){
                temp2.push_back(it.first);
            }
        }
        sort(temp2.begin(),temp2.end());
        ans.push_back(temp2);
        for(auto it:lost){
            if(it.second==1){
                temp.push_back(it.first);
            }
        } 
        sort(temp.begin(),temp.end());
        ans.push_back(temp);
        return ans;
    }
};