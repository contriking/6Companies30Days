string encode(string src)
{     
    //Your code here 
    string ans="";
    int n=src.size();
    int i=0;
    while(i<n){
        int e=i;
        while(e<n && src[i]==src[e]){
            e++;
        }
        ans+=src[i];
        ans+=to_string(e-i);
        i=e;
    }
    return ans;
}