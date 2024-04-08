class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int j = 0;
        
        while(students.size()){
            bool b = false;
            for(int i=0;i<students.size();i++){
                if(students[0] == sandwiches[j]){
                    b = true;
                    j++;
                }else
                    students.push_back(students[0]);
                    
                students.erase(students.begin());
            }
            if(b == false)
                return students.size();
        }
        
        return 0;
    }
};