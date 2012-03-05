import java.util.*;
import dataStructs.*;

public class ch2_redux{

    public static LinkedListNode removeDuplicates(LinkedListNode n){
	//node is unsorted so that probbaly means order is not an issue
        //still, assuming order is an issue -> iterate through and remove element
        Hashtable<Integer, Integer> hashy = new Hashtable<Integer, Integer>(); 
        LinkedListNode explorer=n;
        hashy.put(new Integer(explorer.getData()), new Integer(explorer.getData()));
        while(explorer.getNext()!=null){  //assume no cycles in list!
	    if(hashy.containsKey(new Integer(explorer.getNext().getData()))){
		explorer.setNext(explorer.getNext().removeFront());
	    }else{
		hashy.put(new Integer(explorer.getNext().getData()), new Integer(explorer.getNext().getData()));
	        explorer=explorer.getNext();
	    }
	}
        return n;
    }

    public static void main(String[] args){
	//build a linked list to test 
        LinkedListNode node=new LinkedListNode(10);
        for(int i=20; i>0;i--){
            node=node.insertBefore(new LinkedListNode(i%10));
	}
        //validate our list by printing it out
        System.out.print(node.toString()+"\n");

        //run tests
        System.out.print(removeDuplicates(node).toString()+"\n");
	return;
    }
}
        
