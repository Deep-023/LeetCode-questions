class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int j = 0;
        queue<int> q;
        for(int i=0;i<students.size();i++)
            q.push(students[i]);
        
        while(!q.empty()){
            bool b = false;
            for(int i=0;i<q.size();i++){
                if(q.front() == sandwiches[j]){
                    b = true;
                    j++;
                }else
                    q.push(q.front());
                    
                q.pop();
            }
            if(b == false)
                return q.size();
        }
        
        return 0;
    }
};