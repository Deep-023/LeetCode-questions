class MyCalendar {
public:
    vector<int> st, ed;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(!st.size()){
        st.push_back(start);
        ed.push_back(end);
            return true;
        }
        
        for(int i=0;i<st.size();i++){
            if( (st[i]<=start && start<ed[i]) || (st[i]<end && end <ed[i]) || (st[i]>start && ed[i] <= end) )
                return false;
        }
        st.push_back(start);
        ed.push_back(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */