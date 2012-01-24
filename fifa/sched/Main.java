package sched;

import java.io.*;
import java.util.ArrayList;
import java.util.Random;


/**
 * Scheduling program for round-robin leagues.
 * author:  Dan Cashman  02/25/11
 */
public class Main {

 /**
 * print_round() - a routine to print the match ups for a given round given an array and its size
 * params:
 *   String[] players - the array containing the players in each of their positions (must be odd)
 *   String initial - the initial player
 *   int num - the number of players in the array
     int round_num - the round number to print
 * return: void, no return value
 */

public static void print_round(String[] players, String initial, int num, int round_num){
    //Normal output header-stuff
    System.out.println("\nRound " + round_num + ":");
    //print out initial vs first in array and format nicely
    System.out.println(String.format("%-20s", initial) + "    " + players[0]);
    //for the remaining players, print out the ith element with the corresponding num - ith element
    for(int i=1; i<(num+1)/2;i++){
        System.out.println(String.format("%-20s",players[i]) + "    " + players[num-i]);
    }
    //tidy up with another return
    System.out.println("\n");
    return;
}
 /**
 * print_round_file() - a routine to print to a file the match ups for a given round given an array and its size
 * params:
 *   String[] players - the array containing the players in each of their positions (must be odd)
 *   String initial - the initial player
 *   int num - the number of players in the array
     int round_num - the round number to print
  *  BufferedWriter writer - the BufferedWriter that will write to a file
 * return: void, no return value
 */

public static void print_round_file(String[] players, String initial, int num, int round_num, BufferedWriter writer){
    try{
        //Normal output header-stuff
        writer.write("\nRound " + round_num + ":\n");
        //print out initial vs first in array and format nicely
        if(round_num%2==0){
            writer.write(String.format("%-20s", initial) + "    " + players[0]+"\n");
	}else{
            writer.write(String.format("%-20s", players[0]) + "    " + initial+"\n");        
	}
        //for the remaining players, print out the ith element with the corresponding num - ith element
        for(int i=1; i<(num+1)/2;i++){
           writer.write(String.format("%-20s",players[i]) + "    " + players[num-i]+"\n");
        }
        //tidy up with another return
        writer.write("\n");
    }catch(IOException ex){
        System.out.println("ABANDON SHIP!!!!!!");  //a metaphorical ship, of course
        System.exit(-1);
    }
    return;
}

    /**
     * main:  Da main routine
     * params: the command line arguments: num players and players (must be even)
     *   args[0]:  the file to write results to
     *   args[1]:  an int, number of players
     *   args[2+]: the names of each player
     */
    public static void main(String[] args) {
        //get the total number of players
        int numPlayers= Integer.parseInt(args[1]);
        //declare an array to hold the n-1 right-most elements
        String[] player_array=new String[numPlayers-1];
        boolean[] playerUsed=new boolean[numPlayers];
        //initialize initial element and array
        String leftMost = args[2];
        ArrayList<Round> list=new ArrayList<Round>();
        Random ranGen=new Random();
        Round roundPlace;
        //initialize array starting with 2nd player (args[2]), but do so randomly
        int randSpot=-1;

        //initialize the BufferedWriter to write to file:
        try{
            BufferedWriter writer = new BufferedWriter(new FileWriter(args[0]));
            for(int z=0; z<2; z++){  //run through once for each number of times everyone goes 'round the robin
		for(int i=0;i<numPlayers;i++){
                    playerUsed[i]=false;
		}
                for(int i=-1;i<numPlayers-1;i++){
                  do{
                    randSpot=ranGen.nextInt(numPlayers);
                  }while(playerUsed[randSpot]);
                  playerUsed[randSpot]=true;
                  if(i==-1){
                      leftMost=args[randSpot+2];
		  }else{
                  player_array[i]=args[randSpot+2];
		  }
                }
                //iterate through all of the rounds starting at 1
                for(int i=1;i<numPlayers;i++){
                   //print out the current round
                   //print_round_file(player_array, leftMost,numPlayers-1,i, writer);
		   roundPlace=new Round(leftMost,player_array,numPlayers-1);
                   list.add(roundPlace); 
                   //move every element in the array over one place
                   String temp = player_array[numPlayers-2];
                   for(int j=(numPlayers-2);j>0;j--){
                      player_array[j]=player_array[j-1];
                   }
                   player_array[0]=temp;
                }
                int randRound=0;
                for(int i=1;i<numPlayers;i++){    //go through entire arrayList
		    randRound=ranGen.nextInt(numPlayers-i);
                    roundPlace=list.get(randRound);
                    print_round_file(roundPlace.playerArray,roundPlace.left,numPlayers-1,i+(z*(numPlayers-1)),writer);
                    list.remove(randRound);
		}
                writer.flush();  //write out what you have
	    }
        }catch(IOException ex){
            System.out.println("Could not initialize BufferedWriter! THE END IS NIGH!");
            System.exit(-1);
        }
    }

}
