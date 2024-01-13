class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        int mid=n/2;
        int val=nums[mid];
        int left=mid-1,right=mid+1;
        while(left>=0 || right <n){
            if(left>=0){
                ans+=val-nums[left];
                left--;
            }
            if(right<n){
                ans+=nums[right]-val;
                right++;
            }
        }
        
        return ans;
    }
};