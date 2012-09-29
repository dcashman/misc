package dataStructs;

public class StackWithMin extends Stack{

    private Stack minStack;

    public StackWithMin(){
	super();
        minStack=new Stack();
    }

    public StackWithMin(int data){
	super(data);
        minStack= new Stack(data);
    }

    public int push(int data){
        super.push(data);
        try{
    	    int val=minStack.poll();
            if(val>=data){
	        minStack.push(data);
	    }
	}catch(Exception e){
            minStack.push(data);
	}
            return data;
    }

    public int pop() throws Exception{
	int val=super.pop();
        if(this.poll()==minStack.poll()){  //this was the minimum value 
            minStack.pop();
	}
        return val;
    }

    public int min() throws Exception{
	return minStack.poll();
    }
}