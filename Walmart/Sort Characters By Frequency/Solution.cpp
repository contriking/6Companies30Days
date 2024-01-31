class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        if(n<=1){
            return s;
        }
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            ans+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};