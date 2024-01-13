class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int prev=0;
                bool found=true;
                for(int k=0;k<n;k++){
                    if(k>=i && k<=j){
                        continue;
                    }
                    if(prev>=nums[k]){
                        found=false;
                        break;
                    }
                    prev=nums[k];
                }
                if(found){
                    ans++;
                }
            }
        }
        return ans;
    }
};