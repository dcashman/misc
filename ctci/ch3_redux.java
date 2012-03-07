import dataStructs.*;
import java.util.Random;

public class ch3_redux{


    public static void main(String[] args){
	//build a linked list to test 
        Stack s=new Stack(10);
        for(int i=20; i>0;i--){
            s.push(i);
	}
        //validate our list by printing it out
        System.out.print(s.toString()+"\n");


        Queue q=new Queue(10);
        for(int i=20; i>0;i--){
            q.enqueue(i);
	}
        //validate our list by printing it out
        System.out.print(q.toString()+"\n");


        //run tests
        Random rando = new Random();
        StackWithMin minnie = new StackWithMin();
        for(int i=0; i<20; i++){
            System.out.print("\ni:\t"+i+"\n");
            minnie.push((int)rando.nextInt(30));
	}
        System.out.print("Minnie Stack:\t"+minnie.toString()+"\n");
        System.out.print("Testing min\n");
        int count=1;
        try{
	    while(true){
   	        System.out.print("min:\t"+minnie.min()+"\n");
                minnie.pop();
                count++;
	    }
	}catch(Exception e){
	}
        System.out.print("Count:\t"+count+"\n");
	return;
    }
}
        
