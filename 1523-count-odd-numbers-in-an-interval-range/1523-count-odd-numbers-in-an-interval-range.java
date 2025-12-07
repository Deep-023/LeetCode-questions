class Solution {
    public int countOdds(int low, int high) {
        int diff = high-low+1;
        int posCom = diff/2;

        return ((((low&1)==1) && (diff&1)==1) ? 1 : 0) + posCom;
    }
}