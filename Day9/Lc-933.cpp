#include<queue>
using namespace std;
class RecentCounter {
    private:
    queue<int>s;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        s.push(t);
        while(!s.empty()&& s.front()<t-3000)
            {
                s.pop();  
            }
        return s.size();
    }
};
