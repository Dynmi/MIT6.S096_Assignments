#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct List_node_s {
  List_node *next;
  int value;
};

List empty_list( void ) {
  return (List) { .length = 0, .front = NULL };
}

// Allocate memory for a single List_node
List_node* create_node( int value ) {
  List_node *new_node = malloc( sizeof( List_node ) );
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void list_append( List *list, int value ) {
  if( list->front = NULL )
  {
    list->front = create_node(value);
  }else
  {
    List_node *p = list->front;
    for( size_t i=1;i< list->length;++i,p=p->next);
    p->next = create_node(value);
  }
  ++(list->length);
}

void list_insert_before( List *list, int insert, int before ) {
  List_node *prev = list->front,
            *p    = list->front->next;
  
  while(p->next!=NULL)
  {
    if(p->value == before)
    {
      List_node *a = create_node(insert);
      prev->next = a;
      a->next = p;
      return;
    }
  }
}

void list_delete( List *list, int value ) {
  if(list->front == NULL)
  {
    return;
  }
  List_node *prev = list->front;
  List_node *p = list->front->next;
  while(p!=NULL)
  {
    if(p->value==value)
    {
      prev->next = p->next;
      free(p); --(list->length);
      p = prev->next;
    }
    else
    {
      prev = p;
      p = prev->next;
    }
  }
}

void list_apply( List *list, int (*function_ptr)(int) ) {
  List_node *p = list->front;
  while(p->next!=NULL)
  {
    p->value = function_ptr(p->value);
    p = p->next;
  }

}

int list_reduce( List *list, int (*function_ptr)(int, int) ) {
  if( list->front == NULL )
  {
    return 0;
  }

  List_node *p = list->front;
  int result = p->value;
  p=p->next;
  while(p!=NULL)
  {
    result = function_ptr(result,p->value);
    p = p->next;
  }
  return result;
}

// Print out a linked list in human-readable form
void list_print( List list ) {
  if( list.front == NULL ) {
    printf( "{}\n" );
  } else {
    printf( "{ " );

    List_node *p = list.front;
    size_t length = list.length;

    while( p->next != NULL && length > 0 ) {
      printf( "%d -> ", p->value );
      p = p->next; --length;
    }
    printf( "%d }\n", p->value );

    if( length != 1 ) {
      printf( "Error: badly formed list.\n" );
      exit( EXIT_FAILURE );
    }
  }
}

// Frees the memory in List *list
void list_clear( List *list ) {
  List_node *front = list->front;
  size_t length = list->length;

  while( front != NULL && length > 0 ) {
    List_node *next = front->next;
    free( front );
    front = next;
    --length;
  }

  if( length != 0 ) {
    printf( "Error: failed to clean up list properly.\n" );
    exit( EXIT_FAILURE );
  }
}
