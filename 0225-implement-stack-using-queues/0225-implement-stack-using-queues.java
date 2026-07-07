class MyStack {
    private Queue<Integer> q1;
    private Queue<Integer> q2;

    public MyStack() {
        q1 = new LinkedList<Integer>();
        q2 = new LinkedList<Integer>();
    }
    
    public void push(int x) {
        if(!q1.isEmpty()){
            q1.add(x);
        }else {
            q2.add(x);
        }
    }
    
    public int pop() {
        if(q1.isEmpty()){
            while(q2.size() > 1){
              int frnt = q2.poll();  
              q1.add(frnt);
            }
            return q2.poll();
        }else if(q2.isEmpty()){
            while(q1.size() > 1){
              int frnt = q1.poll();  
              q2.add(frnt);
            }
            return q1.poll();
        }

        return -1;
    }
    
    public int top() {
        int topElement = this.pop();
        this.push(topElement);

        return topElement;
    }
    
    public boolean empty() {
        return q1.isEmpty() && q2.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */