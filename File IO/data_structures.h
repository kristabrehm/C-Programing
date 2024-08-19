#ifndef _data_structures_h
#define _data_structures_h 1

typedef struct TAG_NODE{
    double	key;
    TAG_NODE 	*next;
}NODE;

typedef struct TAG_LIST{
    NODE	*head;
    NODE	*tail;
}LIST;

#endif
