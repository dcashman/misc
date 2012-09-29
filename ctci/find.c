/*
 *find.c - takes a sorted array of consecutive positive integers and identifies the "missing" value.  eg find() would return 5 for [ 1, 2, 3, 4, 6, 7 ]
 *         we can assume that the input array has such a missing value, and that it contains at least 2 integers 
 *         solution, we can determine where the 
 */

int find(int array[], int size){
  //base case
  if(size==2){
    return array[1]-1;
  }
  int middle=size/2;  
  int firstVal=array[0];  //first value on which to base our calculations
  if(array[middle]>firstVal+middle){
    return find(array, middle+1);
  }else{
    return find(array+middle, size-middle+1);  
  }
}
  


 
