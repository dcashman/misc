#include "test.h"


int main(int argc, char *argv[]){
  TEST_STATUS status;
  int test_num, pass_num;
 
  test_num =0;
  pass_num = 0;
  printf("\nBeginning tests...\n");
 
  status = s_l_list_test();
  printf("Singly Linked List Test(s)");
  if(status == TEST_FAILURE){
    printf("\t\tFAILURE\n");
  }else{
    printf("\t\tSUCCESS\n");    
    pass_num++;
  }
  test_num++;

  printf("Total tests passed:\t%d out of %d\n",
	 pass_num, test_num);

  return 0;
}
