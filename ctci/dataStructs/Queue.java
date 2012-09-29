package dataStructs;

public class Queue{

    private Node head;
    private Node tail;

    public Queue(){
        head=null;
	tail=null;
    }

    public Queue(int data){
	Node n = new Node(data);
        n.next=null;
	head=n;
	tail=n;
    }

    public void enqueue(int data){
	Node n = new Node(data);
        n.next=null;
        if(tail!=null){
           tail.next=n;
           tail=n;
	}else{
	    head=n;
            tail=n;
	}
        return;
    }

    public int dequeue(){
	Node n = head;
        head=n.next;
        n.next=null;
        return n.data;
    }

    public String toString(){
        StringBuffer buffy = new StringBuffer();
	Node explorer = head;
        while(explorer!=null){
	    buffy.append(explorer.toString()+", ");
            explorer=explorer.next;
	}
        return new String(buffy);
    }

}