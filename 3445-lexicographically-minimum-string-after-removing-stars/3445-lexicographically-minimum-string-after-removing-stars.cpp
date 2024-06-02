class Solution {
public:
    class comp {
    private:
        const string& ms;
    public:
        comp(const string& s) : ms(s) {}

        bool operator()(int id1, int id2) {
            if (ms[id1] == ms[id2]) {
                return id1 < id2;
            } else {
                return ms[id1] > ms[id2];
            }
        }
    };

    string clearStars(string s) {
        comp cmp(s); // Create an instance of comp with string s
        priority_queue<int, vector<int>, comp> minhp(cmp);
        int n = s.size();
        string ms = s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!minhp.empty()) {
                    int removeIndex = minhp.top();
                    minhp.pop();
                    ms[removeIndex] = '!'; 
                }
            } else {
                minhp.push(i);
            }
        }

        string ans;
        for (int i = 0; i < n; i++) {
            if ( ms[i] != '*' && ms[i] != '!') {
                ans.push_back(ms[i]);
            }
        }

        return ans;
    }
};