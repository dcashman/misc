#ifndef S_L_LIST_H
#define S_L_LIST_H

/* Header file for simple singly linked 
 * list used for ctci questions.
 * @ Dan Cashman
 */
#include <stdlib.h>
#include "datastructs.h"

typedef int node_data_t;
typedef struct s_l_list_node_t_ {
  node_data_t data;   //can be void ptr for generality
  struct s_l_list_node_t_ *next;
} s_l_list_node_t;

typedef struct s_l_list_t_ {
  s_l_list_node_t *head;
  s_l_list_node_t *tail;
} s_l_list_t;


DS_STATUS s_l_list_init(s_l_list_t **list);

DS_STATUS s_l_list_free(s_l_list_t *list);

DS_STATUS s_l_list_append(s_l_list_t *list, node_data_t data);

DS_STATUS s_l_list_print(s_l_list_t *list);

#endif
