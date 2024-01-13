class Solution {
private:
    int smooter(vector<vector<int>>& img,int i,int j){
        int total=0,cnt=0;
        int n=img.size(),m=img[0].size();
        int top=max(0,i-1);
        int bottom=min(n,i+2);
        int left=max(0,j-1);
        int right=min(m,j+2);

        for(int row=top;row<bottom;row++){
            for(int col=left;col<right;col++){
                total+=img[row][col];
                cnt++;
            }
        }
        return total/cnt;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=smooter(img,i,j);
            }
        }
        return ans;
    }
};