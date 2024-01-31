class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries){
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<nums.size();i++){
                int n=nums[i].size();
                int x=n-it[1];
                string s=nums[i].substr(x,it[1]);
                if(pq.size()<it[0]){
                    pq.push({s,i});
                }
                else{
                    if(pq.top().first>s){
                        pq.pop();
                        pq.push({s,i});
                    }
                }
            }
            int val=pq.top().second;
            ans.push_back(val);
        }
        return ans;
    }
};