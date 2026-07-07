class MinStack {
    private Stack<Integer> stk;
    private Stack<Integer> minStk;

    public MinStack() {
        stk = new Stack<Integer>();
        minStk = new Stack<Integer>();
    }
    
    public void push(int value) {
        if(minStk.empty()){
            minStk.push(value);
        }else{
            int stk_min = minStk.peek();
            if(value < stk_min) minStk.push(value);
            else minStk.push(stk_min);
        }

        stk.push(value);
    }
    
    public void pop() {
        stk.pop();
        minStk.pop();
    }
    
    public int top() {
        return stk.peek();        
    }
    
    public int getMin() {
        return minStk.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */