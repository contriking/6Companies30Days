class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return;
        }  
        priority_queue<int>pq;
        for(int i:nums){
            pq.push(i);
        }
        int i=1;
        while(i<n && !pq.empty()){
            nums[i]=pq.top();
            pq.pop();
            i+=2;
        }
        i=0;
        while(i<n && !pq.empty()){
            nums[i]=pq.top();
            pq.pop();
            i+=2;
        }
    }
};