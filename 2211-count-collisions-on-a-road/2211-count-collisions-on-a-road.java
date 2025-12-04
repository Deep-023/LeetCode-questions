class Solution {

    public Object[] getValue(char last, char curr, int count){
        if (last == 'R') {
            count -= 1;
        }
        if((last == 'R' && curr == 'L' )){
            return new Object[]{2+count,'S'};
        } else if ((last == 'S' && curr == 'L' ) || (last == 'R' && curr == 'S' )){
            return new Object[]{1+count,'S'};
        } 
        return new Object[]{0,curr};
    }

    public int countCollisions(String dir) {
        int ans = 0;
        char last = '!';
        int count = 0;
        for(int i=0;i<dir.length();i++){
            
            if (last != '!'){
                Object[] data = getValue(last,dir.charAt(i),count);
                ans += (int)data[0];
                last = (char)data[1];
            }else{
                last = dir.charAt(i);
            }
            
            if (dir.charAt(i)=='R'){
                count++;
            }else {
                count=0;
            }
        }

        return ans;
    }
}