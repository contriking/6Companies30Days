class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ans,aIndex,bIndex;
        int x=s.length(),y=a.length(),z=b.length();

        for(int i=0;i<=x-y;i++){
            if(s.substr(i,y)==a){
                aIndex.push_back(i);
            }
        }
        for(int i=0;i<=x-z;i++){
            if(s.substr(i,z)==b){
                bIndex.push_back(i);
            }
        }
        for(int i=0;i<aIndex.size();i++){
            for(int j=0;j<bIndex.size();j++){
                if(abs(aIndex[i]-bIndex[j])<=k){
                    ans.push_back(aIndex[i]);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};