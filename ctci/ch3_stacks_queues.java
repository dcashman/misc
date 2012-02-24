public class ch3_stacks_queues{

    /*
     *p1 - how would you use an array to support 3 stacks
     */
    /*
     *answer: depends on fixed storage, or not.  I would probably have one stack indexed at numbers%3==0, another at numbers%3==1 and numbers%3==2 to
     *        allow for growth (such as an an ArrayList).  Could go the "easy" route and just have 3 fixed-size stacks starting at 0, n/3 and 2n/3.
     *        Could also have 2 stacks grow toward each other or just resize stacks as necessary.
     */

    /*
     *p2 - implement a stack which contains a method "min()" in addition to push() and pop().  All methods should take O(1) time.
     */
    /* 
     * solution: min() must take O(1) time, so calculating it is not possible since that would take O(n).  Instead, modify each node so that it
     * contains the minium up to the point where that node was inserted
     */
    public class StackNode<E>{
	private StackNode next;
        private E data;
        private E min;
        
        
        public StackNode<E>(E data){  //check on generics
	    this.data=data;
            this.min=data;
            this.next=null;
	}
        public void push(StackNode<E> s){
	    s.next=this;
            s.min=Math.min(this.min,s.data);
	    return;
	}
        public StackNode<E> pop(StackNode<E> s){
            StackNode<E> returner=this;
            this=this.next;
            returner.next=null;
            return returner;
	}
    }