// Design a max stack that supports push, pop, top, peekMax and popMax.

// push(x) -- Push element x onto stack.
// pop() -- Remove the element on top of the stack and return it.
// top() -- Get the element on the top.
// peekMax() -- Retrieve the maximum element in the stack.
// popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
// Example 1:
// MaxStack stack = new MaxStack();
// stack.push(5); 
// stack.push(1);
// stack.push(5);
// stack.top(); -> 5
// stack.popMax(); -> 5
// stack.top(); -> 1
// stack.peekMax(); -> 5
// stack.pop(); -> 1
// stack.top(); -> 5
// Note:
// -1e7 <= x <= 1e7
// Number of operations won't exceed 10000.
// The last four operations won't be called when stack is empty.


class MaxStack {
    
    class Node {
        public Node prev, next;
        public int val;
        
        public Node(int val) {
            this.val = val;
        } 
    }
    
    private Node head, tail;
    private TreeMap<Integer, List<Node>> map;
    
    /** initialize your data structure here. */
    public MaxStack() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
        map = new TreeMap<>();
    }
    
    public void push(int x) {
        Node n = new Node(x);
        tail.prev.next = n;
        n.prev = tail.prev;
        n.next = tail;
        tail.prev = n;
        if (!map.containsKey(x)) map.put(x, new ArrayList<Node>());
        map.get(x).add(n);
    }
    
    public int pop() {
        int v = tail.prev.val;
        remove_node(tail.prev);
        int s = map.get(v).size();
        map.get(v).remove(s - 1);
        if (s == 1) map.remove(v);
        return v;
    }
    
    public int top() {
        return tail.prev.val;
    }
    
    public int peekMax() {
        return map.lastKey();
    }
    
    public int popMax() {
        int v = map.lastKey();
        int s = map.get(v).size();
        Node n = map.get(v).remove(s - 1);
        if (s == 1) map.remove(v);
        remove_node(n);
        return v;
    }
    
    private void remove_node(Node n) {
        n.prev.next = n.next;
        n.next.prev = n.prev;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
