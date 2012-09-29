#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 *uniqueChar - test to see if a string contains all unique characters
 * no bools so return -1 if false, 0 otherwise
 */
int p1a(char s[]){
  //assume ascii string -> no more than 256 characters
  //assume ints are 32 bits  256/32 = 2^8/2^5 = 2^3
  int hashy[8];  //assume initialized to 0
  int test=0;  //tester for bit operations
  if(strlen(s)>256){
    return -1;
  }
  for(int i=0;i<strlen(s);i++){
    int value=s[i];
    test=1 << (value%32);
    printf("Value of test:\t%d\n",test);
    printf("Hashy[test/32]\t%d\ttest%%32\t%d\n",hashy[test/32],test);
    if(test & hashy[value/32]){
      printf("Value of test on failure:\t%d\n",test);
      return -1;
    }else{
      hashy[value/32] = hashy[value/32] | test;
    }
    printf("Hashy[test/32]\t%d\ttest%%32\t%d\n",hashy[test/32],test);
  }
  return 0;
}

int main(int argc, char* argv[]){
  int numProbs=atoi(argv[1]);
  for(int i=0;i<numProbs;i++){
    printf("Testing Problem %d\n", i);
  }
  int prob1Sol=p1a("abcdeff");
  printf("Solution to problem 1:\t%d\n",prob1Sol);

  return 0;
}