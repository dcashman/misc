package dataStructs;
public class BinaryTreeNode{

    protected int data;
    private BinaryTreeNode parent;
    private BinaryTreeNode leftChild;
    private BinaryTreeNode rightChild;

    public BinaryTreeNode(int data){
        this.data=data;
        this.parent=null;
        this.leftChild=null;
        this.rightChild=null;
    }

    public void add(int data){
        BinaryTreeNode n = new BinaryTreeNode(data);
        if(leftChild==null){
            leftChild=n;
            n.parent=this;
	}else if(rightChild==null){
            rightChild=n;
            n.parent=this;
	}else{
            //since this is not a binary search tree, just add it to the side that has the shortest height
            if(rightChild.height() > leftChild.height()){ 
                leftChild.add(data);
	    }else{
		rightChild.add(data);
	    }
	}
        return;
    }

    public int depth(){
        if(parent==null){
            return 0;
	}else{
            return 1+parent.depth();
	}
    }

    public int height(){
        if(leftChild==null && rightChild==null){
            return 0;
	}else if(leftChild==null){
            return 1+rightChild.height();
	}else if(rightChild==null){
            return 1 + leftChild.height();
        }else{
            return 1+Math.max(leftChild.height(), rightChild.height());
	}
    }

    public int isBalanced(){
        int temp;
	if(this.leftChild==null && this.rightChild==null){
	    return 0;
	}else if(rightChild==null){
	    temp=leftChild.isBalanced();
	    if(temp==-1 || temp > 1){
		return -1;
	    }
	    return 1+temp;
	}else if(leftChild==null){
	    temp=rightChild.isBalanced();
	    if(temp==-1 || temp > 1){
		return -1;
	    }
	    return 1+temp;
	}else{
	    int temp2=rightChild.isBalanced();
            temp=leftChild.isBalanced();
	    if(temp==-1 || temp2==-1 || (Math.abs(temp-temp2)>1)){
		return -1;
	    }
	    return Math.max(temp, temp2) + 1;
	}
    }

    public String toStringInOrder(){
	String leftVal, currentVal, rightVal;
        if(this.leftChild==null){
	    leftVal="BLAH";
	}else{
	    leftVal=leftChild.toStringInOrder();
	}
	if(this.rightChild==null){
	    rightVal="BLAH";
	}else{
	    rightVal=rightChild.toStringInOrder();
	}
	currentVal=this.data+", "; //hoping for implicit cast
	return leftVal + currentVal + rightVal;
    }
        
}
       