class Solution {
public:

    int minute(string a){
        int min=0;
        for(int i=0;i<a.length();i++){
            min=min*10+(a[i]-'0');
        }
        return min;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n=access_times.size();
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            string s=access_times[i][1];
            int time=minute(s.substr(0,2))*60+ minute(s.substr(2));
            mp[access_times[i][0]].push_back(time);
        }
        vector<string>ans;
        for( auto it:mp){
            string ch=it.first;
            vector<int>sweep(1441,0);
            vector<int>min=it.second;
            for(int i:min){
                sweep[i]++;
                if(i+60 < 1441){
                    sweep[i+60]--;
                }
            }
            int c=0;
            for(int i=0;i<1441;i++){
                c+=sweep[i];
                if(c>=3){
                    ans.push_back(ch);
                    break;
                }
            }
        }
        return ans;
    }
};