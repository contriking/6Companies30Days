/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(int low,int high,MountainArray &mountainArr){
        while(low!=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    } 
    int binary(int low,int high,int target, MountainArray &mountainArr,bool rev){
        while(low!=high){
            int mid=low+(high-low)/2;
            if(rev){
                if(mountainArr.get(mid)>target){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }else{
                if(mountainArr.get(mid)<target){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }
        }
        return low;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peakIdx=peak(0,n-1,mountainArr);
        int incidx=binary(0,peakIdx,target,mountainArr,false);
        if(mountainArr.get(incidx)==target){
            return incidx;
        }
        int decidx=binary(peakIdx+1,n-1,target,mountainArr,true);
        if(mountainArr.get(decidx)==target){
            return decidx;
        }
        return -1;
    }
};