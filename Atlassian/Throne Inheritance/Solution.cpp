class ThroneInheritance {
public:
    unordered_map<string,vector<string>>mp;
    unordered_set<string>s;
    string king;
    ThroneInheritance(string kingName) {
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        s.insert(name);
    }
    
    void help(vector<string>&ans,string name){
        if(s.count(name)==0){
            ans.push_back(name);
        }
        for(auto it:mp[name]){
            help(ans,it);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string>ans;
        help(ans,king);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */