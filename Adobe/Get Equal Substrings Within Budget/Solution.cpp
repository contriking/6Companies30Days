class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        if(n<=1){
            return 1;
        }
        vector<int>diff;
        for(int i=0;i<n;i++){
            int d=abs(s[i]-t[i]);
            diff.push_back(d);
        }
        int left=0,right=0;
        int ans=0;
        int cost=0;
        while(right<diff.size()){
            cost+=diff[right];
            right++;
            while(cost>maxCost && left<right){
                cost-=diff[left];
                left++;
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};