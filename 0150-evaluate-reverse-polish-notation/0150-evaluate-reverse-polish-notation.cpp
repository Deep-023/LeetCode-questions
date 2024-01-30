class Solution {
public:
    
    int calc(char opr, int a , int b){
        if(opr == '+')
            return a+b;
        else if(opr == '-')
            return a-b;
        else if(opr == '/')
            return a/b;
        return a*b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            int last = tokens[i].size()-1;
            if(tokens[i][last] == '+' || tokens[i][last] == '-' || tokens[i][last] == '*' || tokens[i][last] == '/' ){
                int a= st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int num = calc(tokens[i][last],b,a);
                st.push(num);
            }else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        int num = st.top();
        return num;
    }
};