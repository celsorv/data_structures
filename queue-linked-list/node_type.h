/*********
 * Queue using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#ifndef NODETYPE_H
#define NODETYPE_H

typedef char ItemType;

struct NodeType
{
    ItemType info;
    NodeType* next;
};

#endif
