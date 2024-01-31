class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=k){
            return nums;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<int>idx;
        vector<int>ans;
        while(!pq.empty() && k){
            idx.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(idx.begin(),idx.end());
        for(int i=0;i<idx.size();i++){
            ans.push_back(nums[idx[i]]);
        }
        return ans;
    }
};