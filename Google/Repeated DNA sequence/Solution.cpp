class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        vector<string>ans;
        if(n<10){
            return ans;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n-9;i++){
            string val=s.substr(i,10);
            mp[val]++;
        }
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};