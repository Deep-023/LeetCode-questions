class Solution {
public:
    string intToRoman(int num) {
        map<int,string, greater<int>> m;
        m={
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        string ans="";
        auto itr = m.begin();
        while(num){
            if(num-itr->first >= 0){
                num = num-itr->first;
                ans.append(itr->second);
            }
            else
                itr++;
        }
        return ans;
    }
};