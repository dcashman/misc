import dataStructs.*;
import java.util.Random;

public class ch4_redux{



    public static void main(String[] args){
        Random randerr = new Random();
	BinarySearchTreeNode newTree = new BinarySearchTreeNode(4);
	int temp;
        for(int i=0; i<20; i++){
            temp=randerr.nextInt(20);
            newTree.add(temp);
	    System.out.print(temp+", ");
	}
	System.out.print("\n"+newTree.toStringInOrder()+"\n");
	return;
    }
}