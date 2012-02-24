public class ch4_trees_graphs{

    /*
     *p1 - implement a function to test whether or not a tree is balanced.  For the sake of this, this means that the heights of the subtrees of a node
     *   differ by at most one
     */
    /*
     * plan - get the height of each node and compare it to its sibling (of which there is only one due to binary tree), return if they are not even
     *        1. first write algorithm to get height of a node.  Then modify it to indicate there is no match (one pass in the tree)
     */

    public static int nodeHeight(TreeNode root){
	if(root==null){
	    return 0;
	}
        if(root.left==null && root.right==null){
	    return 0;
	}else if(root.left==null){
	    return nodeHeight(root.left)+1;
	}else if(root.right==null){
            return nodeHeight(root.right)+1;
	}else{
	    return Math.max(nodeHeight(root.right),nodeHeight(root.left))+1;
	}
    }

    /*
     * modified!
     *  returns -1 if unbalanced, returns a number otherwise.  null tree is considered balanced.
     */
    public static int nodeHeight(TreeNode root){
	if(root==null){
	    return 0;
	}
        if(root.left==null && root.right==null){
	    return 0;
	}else if(root.left==null){
            int temp=nodeHeight(root.right);
            if(temp==-1){
		return -1;
	    }
            return (temp > 0) ? -1 : 1;   //1 because it would be 0 + 1

	}else if(root.right==null){
            int temp=nodeHeight(root.left);
            if(temp==-1){
		return -1;
	    }
            return (temp > 0) ? -1 : 1;  //1 because it would be 0 + 1
	}else{
	    int left=nodeHeight(root.left);
	    int right=nodeHeight(root.right);
            if(left==-1 || right==-1){
		return -1;
	    }
	    return (Math.abs(left-right)>1) ? -1 : Math.max(left, right);
	}
    }