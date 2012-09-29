package dataStructs;

public class LinkedListNode{
    private int data;
    private LinkedListNode next;

    public LinkedListNode(int data, LinkedListNode next){
	this.data=data;
	this.next=next;
    }

    public LinkedListNode(int data){
	this.data=data;
	this.next=null;
    }

    public LinkedListNode(){
	this.data=0;
	this.next=null;
    }
    public int getData(){
	return this.data;
    }

    public void setData(int ddata){
	this.data=data;
	return;
    }

    public LinkedListNode getNext(){
	return this.next;
    }

    public void setNext(LinkedListNode next){
	this.next=next;
	return;
    }
  
    public void insertAfter(LinkedListNode next){
        if(next==null){
	    System.out.print("No node inserted, erroneous node\n");
	    return;
	}
        if(next.next!=null){
	    System.out.print("next is not a single node, but rather a list\n");
	    return;
	}
	if(this.next==null){
	    this.next=next;
	}else{
	    next.next=this.next;
	    this.next=next;
	}
	return;
    }

    public void insertListAfter(LinkedListNode next){
        if(next==null){
	    System.out.print("No node inserted, erroneous node\n");
	    return;
	}
	if(this.next==null){
	    this.next=next;
	}else{
	    next.next=this.next;
	    this.next=next;
	}
	return;
    }

    public LinkedListNode insertBefore(LinkedListNode front){
        if(front==null){
	    System.out.print("No node inserted, erroneous node\n");
	    return this;
	}
        if(front.next!=null){
	    System.out.print("front is not a single node, but rather a list\n");
	    return this;
	}      
        front.next=this;
	return front;
    }

    public LinkedListNode removeFront(){
	if(this.next==null){
	   return null;
	}else{
	    LinkedListNode temp=this.next;
	    this.next=null;
	    return temp;
	}
    } 

    public String toString(){
        StringBuffer manipString = new StringBuffer();
        LinkedListNode explorer = this;
	while(explorer!=null){
	    manipString.append(explorer.data+", ");
            explorer=explorer.next;
	}
	return new String(manipString);
    }



}