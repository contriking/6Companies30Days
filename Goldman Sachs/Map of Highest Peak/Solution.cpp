class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 && xx<n && yy>=0 && yy<m && ans[xx][yy]>1+ans[x][y]){
                    ans[xx][yy]=1+ans[x][y];
                    q.push({xx,yy});
                }
            }
        }
        return ans;
    }
};