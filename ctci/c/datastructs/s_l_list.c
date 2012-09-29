#include "s_l_list.h"


DS_STATUS s_l_list_node_init(s_l_list_node_t **node, node_data_t data){
  *node = malloc(sizeof(**node));
  if(*node == NULL){
    printf("Error allocating singly linked list node\n");
    return DS_FAILURE;
  }
  (*node)->next = NULL;
  (*node)->data = data;
  return DS_SUCCESS;
}

DS_STATUS s_l_list_node_free(s_l_list_node_t *node){
  free(node);
  return DS_SUCCESS;
}

DS_STATUS s_l_list_init(s_l_list_t **list){
  *list = malloc(sizeof(**list));
  if(*list == NULL){
    printf("Error allocating singly linked list\n");
    return DS_FAILURE;
  }
  (*list)->head = NULL;
  (*list)->tail = NULL;
  return DS_SUCCESS;
}

DS_STATUS s_l_list_free(s_l_list_t *list){
  s_l_list_node_t *del;
  s_l_list_node_t *node = list->head;
  while(node->next !=NULL){
    del = node;
    node = node->next;
    s_l_list_node_free(del);
  }
  s_l_list_node_free(node);
  free(list);
  return DS_SUCCESS;
}

DS_STATUS s_l_list_append(s_l_list_t *list, node_data_t data){
  DS_STATUS status;
  s_l_list_node_t **new_node_ptr;
  new_node_ptr = malloc(sizeof(*new_node_ptr));
  if(NULL == new_node_ptr){
    printf("%s: Error creating pointer to node\n", __func__);
    return DS_FAILURE;
  }
  //init node
  if((status = s_l_list_node_init(new_node_ptr, data)) != DS_SUCCESS){
    free(new_node_ptr);
    s_l_list_free(list);
    return DS_FAILURE;
  }
  //add node to list
  if(list->tail == NULL){
    list->head = *new_node_ptr;
    list->tail = *new_node_ptr;
  }else{
    list->tail->next = *new_node_ptr;
    list->tail = *new_node_ptr;
  }
  return DS_SUCCESS;
}
  
DS_STATUS s_l_list_print(s_l_list_t *list){
  s_l_list_node_t *node = list->head;
  if(node == NULL){
    printf("Nothing to print in list\n");
    return DS_FAILURE;
  }
  while(node->next != NULL){
    printf("%d, ", (int)node->data);
    node = node->next;
  }
  printf("%d\n", (int)node->data);
  return DS_SUCCESS;
}