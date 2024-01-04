class Solution {
public:
    void rec(vector<vector<int>>& ans,vector<int>curr,int size,int currSum,int currVal){
        if(currSum<0 || curr.size()>size){
            return;
        }
        if(currSum==0 && curr.size()==size){
            ans.push_back(curr);
            return;
        }
        for(int i=currVal;i<=9;i++){
            // Take the current number(i) into the combination
            curr.push_back(i);
            rec(ans,curr,size,currSum-i,i+1);
            // Remove the current number(i) from the combination i.e. Backtracking
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        rec(ans,curr,k,n,1);
        return ans;
    }
};