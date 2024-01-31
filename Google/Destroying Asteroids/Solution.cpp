class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        bool ans=true;
        if(asteroids.size()==1 && mass>=asteroids[0]){
            return true;
        }
        long long m=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(m>=asteroids[i]){
                m+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return ans;
    }
};