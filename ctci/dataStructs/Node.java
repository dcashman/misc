package dataStructs;

public class Node {

    public int data;
    public Node next;

    public Node(int data, Node next){
	this.data=data;
        this.next=next;
    }
   
    public Node(int data){
	this.data=data;
        this.next=null;
    }
 
    public Node(){
	this.data=0;
        this.next=null;
    }
    

    public int getData(){
        return this.data;
    }

    public Node getNext(){
        return this.next;
    }

    public String toString(){
        return new String((new Integer(this.data)).toString());
    }


}
    