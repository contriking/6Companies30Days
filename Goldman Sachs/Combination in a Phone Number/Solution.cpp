class Solution {
public:
    void rec(vector<string>&ans,string output,string num[],string digits,int index){
        if(index==digits.size()){
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string value=num[number];
        for(int i=0;i<value.size();i++){
            output+=value[i];
            rec(ans,output,num,digits,index+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string output;
        string num[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        rec(ans,output,num,digits,index);
        return ans;
    }
};