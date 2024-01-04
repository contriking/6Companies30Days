class Solution {
public:
    set<pair<int,int>>st;
    int r,c;
    Solution(int m, int n) {
        r=m;
        c=n;
    }
    
    vector<int> flip() {
        int x=rand()%r;
        int y=rand()%c;
        if(st.find({x,y})==st.end()){
            st.insert({x,y});
            return {x,y};
        }
        return flip();
    }
    
    void reset() {
        st.clear();
    }
};
