package dataStructs;
import java.util.*;

public class TreeNode{
    
    private int data;
    private TreeNode parent;
    pivate LinkedList<TreeNode> children;
    
    public TreeNode(int data){
        this.data=data;
        this.parent=null;
        this.children=new LinkedList<TreeNode>();
    }

    public void addChild(int data){
        
        this.children.add(new TreeNode(data));
    }
   
    public int removeChild(int data){  //removes first child of "data" type
        return -1;
    }
}
