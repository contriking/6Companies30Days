class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans=0;
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            vector<int>v;
            for(int j=i;j<n;j++){
                int x=nums[j];
                v.push_back(x);
                if(x%p==0){
                    cnt++;
                }
                if(cnt>k){
                    break;
                }
                st.insert(v);
            }
        }
        return st.size();
    }
};