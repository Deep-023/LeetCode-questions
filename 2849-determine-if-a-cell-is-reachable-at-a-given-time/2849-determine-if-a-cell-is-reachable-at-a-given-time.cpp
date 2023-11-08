class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDis = abs(fx-sx), yDis = abs(fy-sy);
        if(xDis==0 && yDis==0 && t==1)
            return false;
        return (max(xDis,yDis) <= t);
    }
};