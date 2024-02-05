class Solution {
public:
    bool check(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }

    void dfs(string &s,string &s1,string &s2,int &ans,int i){
        if(i>=s.size()){
            if(check(s1) && check(s2)){
                int temp=s1.length()*s2.length();
                ans=max(ans,temp);
            }
            return;
        }
        // Don't pick
        dfs(s,s1,s2,ans,i+1);
        // pick for s1
        s1.push_back(s[i]);
        dfs(s,s1,s2,ans,i+1);
        s1.pop_back();

        // pick for s2
        s2.push_back(s[i]);
        dfs(s,s1,s2,ans,i+1);
        s2.pop_back();
    }

    int maxProduct(string s) {
        int ans=0;
        string s1="";
        string s2="";
        dfs(s,s1,s2,ans,0);
        return ans;
    }
};