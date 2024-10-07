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
    int findPeak(MountainArray &mountainArr, int low, int high){
        int peak=high;
        

        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }
            else {
                peak=mid;
                high=mid;
            }
        }
        return low;
    }
    int bSearch1(MountainArray &mountainArr, int low, int high, int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid)>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return -1;
    }
    int bSearch2(MountainArray &mountainArr, int low, int high, int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target)return mid;
            else if(mountainArr.get(mid)>target)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, 0, n - 1);
        
        // Try to find the target in the increasing part (left of peak)
        int result = bSearch1(mountainArr, 0, peak, target);
        if(result != -1) return result; // If found, return the result
        
        // Otherwise, search in the decreasing part (right of peak)
        return bSearch2(mountainArr, peak + 1, n - 1, target);
    }
};