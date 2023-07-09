/*class MyCalendar {
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
*/
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class MyCalendar {
    map<int, int> mp;   // <endTime, statIme>
public:  
    bool book(int start, int end) {
        /*lookfor first endTIme that is larger than start time request. First condition checkes if the incoming request should be added to the list of booked slots.*/
        auto itr = mp.upper_bound(start);
        if(itr == mp.end() || end<= itr->second) {
            mp[end]=start;
            return true;
        } 
        else  return false;
    }
};