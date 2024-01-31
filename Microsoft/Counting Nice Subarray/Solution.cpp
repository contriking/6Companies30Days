class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]++;
        int ans=0;
        int oddCnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                oddCnt++;
            }
            if(mp.find(oddCnt-k)!=mp.end()){
                ans+=mp[oddCnt-k];
            }
            mp[oddCnt]++;
        }
        return ans;
    }
};
