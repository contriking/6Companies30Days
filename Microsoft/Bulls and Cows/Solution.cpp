class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int>secret;
        unordered_map<char,int>guess;
        int bull=0,cow=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char sec=s[i];
            char gue=g[i];
            if(sec==gue){
                bull++;
            }
            else{
                guess[sec]++;
                secret[gue]++;
            }
        }
        for(auto it:secret){
            if(guess.find(it.first)!=guess.end()){
                cow+=min(it.second,guess[it.first]);
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};