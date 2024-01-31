class Solution {
public:
    void add(unordered_map<string,int>&mp,string s){
        int n=s.size();
        int init=0;
        for(int i=n;i>0;i--){
            mp[s.substr(init,i)]++;
            init++;
        }
    }

    static bool comp(string s,string t){
        return s.size()>t.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        if(n<=1){
            return words[0].size()+1;
        }
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>mp;
        string s=words[0]+'#';
        add(mp,words[0]);
        for(int i=1;i<n;i++){
            if(mp.find(words[i])==mp.end()){
                s+=words[i]+'#';
                add(mp,words[i]);
            }
        }
        return s.size();
    }
};