import java.util.*;

public class ch2{

    /*
     * 2.1 - implement a method/function that removes all repeated items in a linked list
     *     -again, 2 ways, one is to go through the list over and over, other is to use hash table
     */

    public void removeDups(LinkedListNode dups){       //in java can pass as an object, in C would be a pointer to a struct (head of struct)
	//check to see if there is anything in dups
        if(dups==null){
	    return;
	}else{
            Node current = dups.next;
            Node previous=dups;
            Hashtable hashtabs = new Hashtable();
            hashtabs.put(previous.data);
	    while(current!=null){
		if(hashtabs.containsKey(current.data)){
		    previous.next=current.next;     
		}else{
		    hashtabs.put(current.data);
		}
                previous=current;
                current=current.next;
	    }
	    return;
	}
    }

    /*
     *   2.2 - find the kth to last element in a singly linked list
     */

    public static LinkedListNode kthLast(LinkedListNode n, int k){
	int numNodes=0;     //to get total number of nodes
	LinkedListNode magellan=n;    //explorer to the end of the list
	while(magellan!=null){         
	    numNodes++;
	    magellan=magellan.next;
	}
	if(numNodes<k){
	    return null;
	}else{
	    int destination=numNodes-k+1;     //for example, 2nd to last node in a b c d = c which is 4-2 + 1th node
	    while(destination>0){
		n=n.next;
		destination--;
	    }
	    return n;
	}
    }  

    /*
     * 2.3 - given access to only a node in the middle of a linked list, delete it
     *     - two approaches, given access to that node AND head of list
     *     -               or given access only to that node (as indicated).   - must copy values until reach the end
     */ 
    public static void removeArb(LinkedListNode n){
	//copy everything one to the left until we hit the end
        LinkedListNode prev=null;
        LinkedListNode current=n;
        while(current.next!=null){
	    current.data=current.next.data;
            prev=current;
            current=current.next;
	}
        if(prev!=null){
	    prev.next=null;
	}
        return;
    }
    //solution review:  NOT NECESSARY TO move all nodes, just need to move one of them.  D'oh!

    /*
     * 2.4 - write a function that partitions a linked list around a value x, such that all values less than x come before and all values after come after
     */
    //so approaches - this question is NOT asking us to sort the whole thing, it seems.  Otherwise that would call for mergeSort
    public static void xPart(LinkedListNode n){
	LinkedListNode smallz;
	LinkedListNode equalz;  //for nodes which have data equal to x
	LinkedListNode  equalzHead;
	LinkedListNode biggz;
	LinkedListNode biggzHead;    //need the head of biggs to make sure we know where to connect
	LinkedListNode magellan=n;   //this is to ensure we don’t lose the structure of the list!
	while(magellan!=null){
	    if(magellan.data<x){
		if(smallz==null){
		    smalls=magellan;
		}else{
		    smalls.next=magellan;
		}
	    }else if(magellen.data==x){
		if(equalz==null{
			equalz=magellan;
			equalzHead=magellan;
		    }else{
			equalz.next=magellan;
		    }
		    }same for big//
			 //put them all together
   
      
			 }
	}
    }  


    /*
     * 2.5 -  2.4 (above) not fully written due to time
     *   implement a function which goes through a linked list representing numbers, stored in reverse order and add them
     *   then do it in reverse order
     */ 

     
            