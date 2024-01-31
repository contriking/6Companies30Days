class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            int val=nums[j];
            mp[val]++;
            if(mp[val]>k){
                while(i<j && mp[val]>k){
                    if(mp[nums[i]]==1){
                        mp.erase(nums[i]);
                    }else{
                        mp[nums[i]]--;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};