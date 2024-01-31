class KthLargest {
public:
    // vector<int>mp;
    priority_queue<int,vector<int>,greater<int>>mp;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            if(mp.size()<k){
                mp.push(nums[i]);
            }
            else{
                if(nums[i]>mp.top()){
                    mp.pop();
                    mp.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(mp.size()<k){
            mp.push(val);
            return mp.top();
        }
        else{
            if(mp.top()<val){
                mp.pop();
                mp.push(val);
            }
        }
        return mp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */