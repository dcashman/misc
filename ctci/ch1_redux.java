import java.util.*;

public class ch1_redux{
    /*
     *uniqueChars - returns true if characters in given string are unique, false otherwise
     */
    public static boolean p1a(String s){
	//recommended method 1, map everything to a hash and see if there are collisions
        Hashtable<Character, Character> hashy=new Hashtable<Character, Character>();
        for(int i=0;i<s.length();i++){
	    if(!hashy.containsKey(new Character(s.charAt(i)))){
	      hashy.put(s.charAt(i),s.charAt(i));
	    }else{
		return false;
	    }
	}
	return true;
    }
    /*
     *uniqueCharswOut - without using data structures
     *                  must be done in-place, then.  Can sort string perhaps if it is assumed to be a character array, but simple comparisons work too
     */
    public static boolean p1b(String s){
	char current;
	for(int i=0;i<s.length();i++){
            current=s.charAt(i);
	    for(int j=i+1;j<s.length();j++){
		if(s.charAt(j)==current){
		    return false;
		}
	    }
	}
	return true;
    }

    public static void main(String[] args){
	System.out.print("Beginning test of p1\n");
        boolean uniqueA=p1a("Abcdefg");
        boolean uniqueB=p1b("Abcdefg");
        System.out.print("Value for part A:\t"+uniqueA+"\n");
        System.out.print("Value for part B:\t"+uniqueB+"\n");
	return;
    }
}






