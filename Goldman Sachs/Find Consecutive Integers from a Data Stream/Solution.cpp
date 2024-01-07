class DataStream {
public:
    int cnt=0,val=0;
    int size=0;
    DataStream(int value, int k) {
        val=value;
        size=k;
    }
    
    bool consec(int num) {
        if(num==val){
            cnt++;
        }
        else{
            cnt=0;
        }
        if(cnt>=size){
            return true;
        }
        return false;
    }
};
