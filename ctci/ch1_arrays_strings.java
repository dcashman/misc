import java.util.*;

public class ch1_arrays_strings{
//provided code:

/*
 * simple example of working with a hash table in java
 *  HashMap<Key, Value> -maps Key to a hash value and stores Value there
 */
/*  public HashMap<Integer, Student> buildMap(Student[] students){
    HashMap<Integer, Student> map = new HashMap<Integer, Student>();
    for(Student s: students){
      map.put(s.getId(), s);
    }
    return map;
  }
*/
/*
 * ArrayList use
 */
/*  public ArrayList<String> merge(String[] s1, String[] s2){
      ArrayList<String> list=new ArrayList<String>();
      for(String s: s1){
  	list.add(s);
      }
      for(String s: s2){
          list.add(s);
      }
      return list;
      } */

/*
 *  Evaluate the running time of that below: each word is x characters
 *  A:  Every time a string is added ,the whole string is copied, so the total time = x + 2x + 3x + 4x + 5x = (n+1)nx/2 = O(n^2)
 */
/*  public String joinWords(String[] words){
      String sentence="";
      for (String s: words){
  	sentence+=" " + s;  //does this work for combining strings? book gives: sentence+s
      }
      return sentence;
      }  */

/*
 *  What if we use StringBuffer instead?
 *  A: ... implement your own version of stringBuffer, but basically, StringBuffer just creates an array of words, only copying to a string when necessary
 */

//Provided Problems:
/*
 * 1.1 - implement an algorithm to determine if a string has all unique characters.  What if you cannot use additional data structures?
 * Question:  Are the characters 8 bits? 16?  (ASCII vs. Unicode?) 
 * Question: Desired trade off between space and time?  - see "cannot use data structures"
 */

  public static boolean uniqueChars(String s){
      int size=s.length();       //get lenth of string to use as base of hash size
      HashMap<Character, Boolean> hash = new HashMap<Character, Boolean>(size*4);
      for(int i=0; i<size;i++){
  	if(!hash.containsKey(s.charAt(i))){
  	    hash.put(s.charAt(i), true);
  	}else{
  	    return false;
  	}
      }
      return true;
  }

//also possible to use with an array of 256 spots (one for each possible ascii char)
  public static boolean uniqueChars2(String s){
      boolean[] array = new boolean[256];  //initialized to false?
      for(int i=0; i<s.length();i++){
	  if(array[s.charAt(i)]){
	      return false;
	  }else{
	      array[s.charAt(i)]=true;
	  }
      }
      return true;
  }

    //part 2
    /*
     *implement a function reverse(char* s) which reverses a null-terminated string  in C  (see c file)
     */
        
    /*
     *  part 3 - write a function which detects if one string is a permutation of another
     *    ways to go about this:  
     *    1. keep a hashtable/array of possible characters, increment "count" for each letter encountered, compare the hashes afterward 
     *        a: running time: create hash = (n*factor + n for putting in hash)*2 + 2n for comparison = O(n), 8n space?
     *    2. evaluate each character at a time, going through the first word, going through the second word for every letter n^2, 2n space
     */
    public static boolean permutation(String s1, String s2){
	if(s1.length()!=s2.length()){   //if strings are not same lenght, they cannot be permutations, so end
	    return false;
	}
        HashMap<Character, Integer> hash1=new HashMap<Character, Integer>(s1.length()*8);    //hash for first string
        HashMap<Character, Integer> hash2=new HashMap<Character, Integer>(s2.length()*8);    //hash for second string
        for(int i=0;i<s1.length();i++){       //iterate through both strings
            if(hash1.containsKey(s1.charAt(i))){
		    hash1.put(s1.charAt(i), hash1.get(s1.charAt(i))+1);
	    }else{
                hash1.put(s1.charAt(i),1);
	    }
            if(hash2.containsKey(s2.charAt(i))){
		    hash2.put(s2.charAt(i),hash2.get(s2.charAt(i))+1);
	    }else{
                hash2.put(s2.charAt(i),1);
	    }
	}
        Set set1=hash1.entrySet();
        Set set2=hash2.entrySet();
        if(set1.equals(set2)){
	    return true;
        }else{
	    return false;
	}
    }
           

    public static void zeroMatrix(int[][] matrix){
	//for now we can assume that there IS a matrix
	int numRows=matrix.length;        //give us the number of items in the array of arrays
	int numCols=matrix[0].length;    //all are same, so just go for it
	boolean[] rows=new boolean[numRows];
	boolean[] cols=new boolean[numCols];   //assuming initialized to false;
	for(int i=0; i<numRows;i++){
	   if(rows[i]){
	      continue;
 	   }else{
	      for(int j=0; j<numCols;j++){
		if(cols[j]){
		    continue;
		}else{
		    if(matrix[i,j]==0){
			rows[i]=true;
			cols[j]=true;
			break;   //this should break out of entire loop? yes? yes
		    }
		}
	      }
	   }
        }
	//at the end - replace parts in matrix
	for(int i=0; i<numRows;i++){
	    if(rows[i]){
		for(int j=0; j<numCols;j++){
		    matrix[i,j]=0;
		}
	    }else{
		for(int j=0; j<numCols;j++){
		    if(cols[j]){
			matrix[i,j]=0;
		    }
		}
	    }
	}
    }
 
    public static boolean isRotate(String s1, String s2){
        if(s1.length()!=s2.length() || s1.length()==0){
	    return false;
        }else{
   	  String bigger=s1+s1;
          return isSubstring(bigger, s2);
	}
    }

        

  public static void main(String args[]){
     System.out.print("Hey, is this working?\n\n");
     //test uniqueChars2
      boolean test = uniqueChars2(args[0]);
      if(test){
        System.out.print("Test is true\n");
      }else{
        System.out.print("Test is false\n");
      }
      //test uniquechars1
      boolean test2 = uniqueChars(args[0]);
      if(test){
         System.out.print("Test is true\n");
      }else{
         System.out.print("Test is false\n");
      }
      //test permutation
      if(permutation(args[0], args[1])){
	  System.out.print("Permutations returned true\n");
      }else{
          System.out.print("Permutations returned false\n");
      }
      return;
  }
}
 


    