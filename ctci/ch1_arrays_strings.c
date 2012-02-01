#include <stdio.h>
#include <string.h>

/*part 1.2
 * implement a function char* reverse(char *)
 * two ways to go about this
 * 1. create a stack, add each letter to the stack, then add the letters back FILO
 *     running time = n to add to stack and n to remove = 2n
 * 2. find length of string, replace the 1st with the last, 2nd with second to last, etc
 *     running time = n to find '\0' + n to swap
 */
void reverse(char* c){
  //as directed, string terminates with null character, ignoring security implications here for simplicity
  char* iter=c;
  int count=0;
  int front=0;
  char temp; //a temporary storage for swapping characters
  while(*iter!='\0'){  //go through string until null ending found
    iter++;            
    count++;   //keep track of number of characters (will add all except the \0)
  }
  count--;  //count will be used as an index, so length-1 is appropriate
  while(front<count){  //if front = count, then it is an odd number and doesn't need to be switched, otherwise it'll pass each other
    temp=*(c+count);
    *(c+count)=*(c+front);
    *(c+front)=temp;
    count--;
    front++;
  }
  return;
}

/*part 1.4
 * implement a function that iterates through a string and replaces every instance of a space with %20
 *   approach 1: naive approach - would be to go until a space is found, then move everything 2 spots, to the right, then input %20 where space was and the 2 characters following.  Run time for this will be O(n^2)  (if all spaces, then everything would be moved over 2 spots(n moves), n times
 *  alternatively, could go through the array to count the number of spaces, then move everything over as a function of the number of spaces
 *     this could be done two ways : 1. Count number of spaces, then start from the end and move them over until a space is hit, then adjust the amount each is moved over or 2. keep the position of each space in an array/linked list and use it to calculate the amount to move over
 *   benefits of 1. include that no data structures are created, benefits of 2 are that it is super easy?
 */
void spaceReplacer(char* string, int trueLength){  //assuming true lenght is the true length of the string BEFORE %20 are added
  //not going the array route because it should be more space efficient and same running time, although would require less conditional checks
  int spaceCount=0;
  char* temp; 
  for(int i=0;i<trueLength;i++){
    if(*(string+i)==' '){
      spaceCount++;
    }
  }
  for(int i=(trueLength-1);i>=0;i--){
    if(*(string+i)==' '){
      spaceCount--;
      temp=(string+i)+(2*spaceCount); //only move it over enough to account for earlier spaces
      *temp='%';       //fill in new values
      //sanity check to make sure arithmetic is correct on first run:
      *(temp+1)='2';
      *(temp+2)='0';
    }else{
      temp=(string+i)+(2*spaceCount);
      *temp=*(string+i);  //replace
    }
  }
  return;
}
      
      
  


int main(int argc, char* argv[]){
  printf("Yo, does this appear to be working?\n");
  reverse(argv[1]);
  printf("Reversed:\t%s\n",argv[1]);
  char boo[]="Hello Dave, boo    ";
  spaceReplacer(boo,15);
  printf("SpaceReplaced:\t%s\n", boo);
  
  return 0;
}
