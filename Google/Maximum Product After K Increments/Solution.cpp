class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1){
            return nums[0]+k;
        }     
        long long int mod=1000000007;    
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i:nums){
            pq.push(i);
        }
        while(k>0){
            int val=pq.top();
            pq.pop();
            pq.push(++val);
            k--;
        }
        long int prod=1;
        while(!pq.empty()){
            prod=(prod*pq.top())%mod;
            pq.pop();
        }
        return prod%mod;
    }
};