class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int cnt=1;
        stack<int>st;
        string ans="";
        st.push(cnt);
        for(int i=0;i<S.size();i++){
            if(S[i]=='D'){
                cnt++;
                st.push(cnt);
            }
            else{
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
                cnt++;
                st.push(cnt);
            }
        }
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        return ans;
    }
};