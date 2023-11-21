class MyQueue {

    Stack<Integer> s1 = new Stack<Integer>();
    Stack<Integer> s2 = new Stack<Integer>();

    public MyQueue() {
        
    }
    public void push(int x) {
        s1.push(x);
        
    }
    public int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                int x = s1.pop();
                s2.push(x);
            }
        }
       int res = s2.pop();
        if(s1.empty()){
            while(!s2.empty()){
                int x = s2.pop();
                s1.push(x);
            }
        }
       return res;    
    }
    public int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                int x = s1.pop();
                s2.push(x);
            }
        }
       int res = s2.peek();
        if(s1.empty()){
            while(!s2.empty()){
                int x = s2.pop();
                s1.push(x);
            }
        }
       return res;   
    }
    public boolean empty() {
        return s1.empty();
    }
}