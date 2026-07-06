class MyQueue {
    Stack<Integer> inStack;
    Stack<Integer> outStack;

    public MyQueue() {
        inStack = new Stack<Integer>();
        outStack = new Stack<Integer>();
    }
    
    public void push(int x) {
        inStack.push(x);
    }
    
    public int pop() {
        moveInStackToOutStack();
        int top = outStack.peek();
        outStack.pop();
        return top;
    }
    
    public int peek() {
        moveInStackToOutStack();
        return outStack.peek();
    }
    
    public boolean empty() {
        return inStack.empty() && outStack.empty();
    }

    private void moveInStackToOutStack(){
        if(outStack.empty()){
            while(!inStack.empty()){
                int top = inStack.peek();
                inStack.pop();
                outStack.push(top);
            }
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */