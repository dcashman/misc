//provided code:

/*
 * simple example of working with a hash table in java
 *  HashMap<Key, Value> -maps Key to a hash value and stores Value there
 */
public HashMap<Integer, Student> buildMap(Student[] students){
  HashMap<Integer, Student> map = new HashMap<Integer, Student>();
  for(Student s: students){
    map.put(s.getId(), s);
  }
  return map;
}

/*
 * ArrayList use
 */
public ArrayList<String> merge(String[] s1, String[] s2){
    ArrayList<String> list=new ArrayList<String>();
    for(String s: s1){
	list.add(s);
    }
    for(String s: s2){
        list.add(s);
    }
    return list;
}

/*
 *  Evaluate the running time of that below: each word is x characters
 *  A:  Every time a string is added ,the whole string is copied, so the total time = x + 2x + 3x + 4x + 5x = (n+1)nx/2 = O(n^2)
 */
public String joinWords(String[] words){
    String sentence="";
    for (String s: words){
	sentence+=" " + s;  //does this work for combining strings? book gives: sentence+s
    }
    return sentence;
}

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

public Boolean uniqueChars(String s){
    s.size()
    HashMap<Char, Boolean> hash = new HashMap<Char, Boolean>();
    