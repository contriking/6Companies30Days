class Solution {
public:
    static bool comp(pair<string,int>p1,pair<string,int>p2){
        if(p1.second>p2.second || p2.second==p1.second && p1.first<p2.first){
            return true;
        }
        return false;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }   
        vector<pair<string,int>>vp;
        for(auto it:mp){
            vp.push_back({it.first,it.second});
        }
        sort(vp.begin(),vp.end(),comp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vp[i].first);
        }
        return ans;
    }
};