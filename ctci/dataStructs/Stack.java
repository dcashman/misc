package dataStructs;

public class Stack {

    private Node top;
    

    public Stack(){
	top=null;
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

    public int poll() throws Exception{
        if(top==null){
            throw new Exception();
	}else{
          return top.data;
	}
    }


    public int pop() throws Exception{
        if(top==null){
	    throw new Exception();
	}else{
            Node s = top;
            top=top.next;
            s.next=null;
            return s.getData();
	}
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