#include <stack>
using namespace std;
class MyQueue {
    private:  
    stack<int>instack,outstack;
    public:
    MyQueue() {
        
    }
    
    void push(int x) {
        instack.push(x);
    }
    
    int pop() {
        if(outstack.empty())
        {
            while(!instack.empty())
                {
                    outstack.push(instack.top());
                    instack.pop();
                }
        }
        int val= outstack.top();
        outstack.pop();
        return val;
    }
    
    int peek() {
        if(outstack.empty())
        {
            while(!instack.empty())
                {
                    outstack.push(instack.top());
                    instack.pop();
                }
        }
        return outstack.top();
    }
    
    bool empty() {
        return instack.empty()&&outstack.empty();
    }
};
