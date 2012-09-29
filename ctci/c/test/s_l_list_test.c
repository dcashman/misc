#include "s_l_list_test.h"


TEST_STATUS s_l_list_test(){
  s_l_list_t **list;
  list = malloc(sizeof(*list));
  if(list == NULL){
    return TEST_FAILURE;
  }
  int i;
  if(DS_SUCCESS != s_l_list_init(list)){
    printf("%s: Failure initializing singly linked list\n", 
	   __func__);
    return TEST_FAILURE;
  }
  for(i = 0; i < 6; i++){
    if(DS_SUCCESS != s_l_list_append(*list, (node_data_t)i)){
      printf("%s: Failure adding to singly linked list\n", 
	     __func__);
      return TEST_FAILURE;
    }
  }
  s_l_list_print(*list); //DAC TODO: convert to string and cmp instead
  if(DS_SUCCESS != s_l_list_free(*list)){
    printf("%s: Failure freeing singly linked list\n", 
	   __func__);
    return TEST_FAILURE;
  }  
  

  return TEST_SUCCESS;
}