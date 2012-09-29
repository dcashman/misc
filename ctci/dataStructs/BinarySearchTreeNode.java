package dataStructs;
public class BinarySearchTreeNode extends BinaryTreeNode{
    private BinarySearchTreeNode parent;
    private BinarySearchTreeNode leftChild;
    private BinarySearchTreeNode rightChild;
    public BinarySearchTreeNode(int data){
        super(data);
    }
    //many methods will be the same, except now we need to check 
    public void add(int data){
        BinarySearchTreeNode n = new BinarySearchTreeNode(data);
        if(data>this.data){
            if(rightChild==null){
                rightChild=n;
                n.parent=this;
		return;
	    }else{
		rightChild.add(data);
		return;
	    }
	}else{                     //values that are teh same are added to left branch
            if(leftChild==null){
                leftChild=n;
		n.parent=this;
		return;
	    }else{
		leftChild.add(data);
		return;
	    }
	}
    }

    private BinarySearchTreeNode find(int data){
        //this isn't really all that useful when just dealing with integers, but would be for key-value pairs
        if(this.data==data){
	    return this;
	}else if(data<this.data){
            if(leftChild==null){
		return null;
	    }else{
		return leftChild.find(data);
	    }
	}else{
            if(rightChild==null){
		return null;
	    }else{
		return rightChild.find(data);
	    }
	}
    }

    public boolean inTree(int data){
        if(find(data)==null){
	    return false;
	}else{
	    return true;
	}
    }
	    

    public void remove(int data){  //removes first occurance of this value
	BinarySearchTreeNode n = find(data);
	n.remove();
	return;
    }

    private BinarySearchTreeNode getSmallest(){
        if(this.leftChild==null){
	    return this;
	}
        return leftChild.getSmallest();
    }
    
    public int getSmallestValue(){
	return getSmallest().data;
    }

   
    public void remove(){

            
        //case 2: has one child (easy)
        //case 3: has 2 children (need to find appropriate replacement
	if(rightChild==null && leftChild==null){
	    if(this.data>this.parent.data){
                this.parent.rightChild=null;
	    }else{
		this.parent.leftChild=null;
	    }
	    this.parent=null;
	}else if(rightChild==null){
	    if(this.data>this.parent.data){
		this.parent.rightChild=this.leftChild;
	    }else{
		this.parent.leftChild=this.leftChild;
	    }
	    this.leftChild.parent=this.parent;
	    this.parent=null;
	    this.leftChild=null;

	}else if(leftChild==null){
	    if(this.data>this.parent.data){
		this.parent.rightChild=this.rightChild;
	    }else{
		this.parent.leftChild=this.rightChild;
	    }
	    this.rightChild.parent=this.parent;
	    this.parent=null;
	    this.rightChild=null;        
	}else{  //tricky case, we have 2 children and need to fix-it
	    BinarySearchTreeNode n = this.rightChild.getSmallest();  //getting the "next in line which will fit in
	    this.data=n.data;  //just swap values, structure remains the same
            n.remove();
	}
    }
    
    public String toStringInOrder(){
	String leftVal, currentVal, rightVal;
        if(this.leftChild==null){
	    leftVal="";
	}else{
	    leftVal=leftChild.toStringInOrder();
	}
	if(this.rightChild==null){
	    rightVal="";
	}else{
	    rightVal=rightChild.toStringInOrder();
	}
	currentVal=this.data+", "; //hoping for implicit cast
	return leftVal + currentVal + rightVal;
    }
    
}