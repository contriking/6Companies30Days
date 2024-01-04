class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>ans(2,-1);
        if(n<=1){
            return ans;
        }
        vector<int>freq(n,-1);
        for(int i=0;i<n;i++){
            freq[arr[i]-1]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==-1){
                ans[1]=i+1;
            }
            else if(freq[i]>=1){
                ans[0]=i+1;
            }
        }
        return ans;
    }
};