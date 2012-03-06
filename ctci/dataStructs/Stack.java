package dataStructs;

public class Stack {

    private Node top;
    

    public Stack(){
	top=null;
    }

    public Stack(Node n){
	top=n;
    }

    public Stack(int data){
        Node n = new Node(data);
	top=n;
    }

    public int push(int data){
        Node s = new Node(data);
        s.next=top;
        top=s;
        return data;
    }

    public Node push(Node n){
        n.next=top;
        top=n;
        return n;
    }

    /*    public Node pop(){   //don't use this function though
        if(top==null){
	    return null;
	}
        Node s = top;
        top=top.next;
        s.next=null;
        return s;
	} */

    public int pop(){
        if(top==null){
	    return -1;
	}
        Node s = top;
        top=top.next;
        s.next=null;
        return s.getData();
    }

    public String toString(){
        StringBuffer sBuff = new StringBuffer();
        Node explorer=top;
        while(explorer!=null){
	    sBuff.append(explorer.toString()+", ");
            explorer=explorer.getNext();
	}
        sBuff.append("\n");
        return new String(sBuff);
    }

}