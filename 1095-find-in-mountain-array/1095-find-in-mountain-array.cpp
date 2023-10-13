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
    int findpivot(int n, MountainArray &m ){
        int start = 0, end= n;
        int mid = start + (end-start)/2;
        while(start < end){
            if(m.get(mid) < m.get(mid+1)){
                start = mid+1;
            }else
                end = mid;
            mid = start + (end-start)/2;
        }
        return start;
    }
    
    int findInMountainArray(int target, MountainArray &m) {
        int len = m.length();
        int pivot = findpivot(len-1, m);
        if(m.get(pivot) == target)
            return pivot;
        int start = 0, end = pivot-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start <= end){
            int num = m.get(mid);
            if(num == target){
                ans = mid;
                end = mid-1;
            }
            else if( num < target)
                start = mid+1;
            else
                end = mid-1;
            
            mid = start + (end-start)/2;
        }
        if(ans != -1)
            return ans;
        
        start = pivot+1;
        end = len-1;
        mid = start + (end-start)/2;
        while(start <= end){
            int num = m.get(mid);
            if(num == target){
                ans = mid;
                end = mid-1;
            }
            else if( num > target)
                start = mid+1;
            else
                end = mid-1;
            
            mid = start + (end-start)/2;
        }
        
        return ans;
        
    }
};