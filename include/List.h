#include <stddef.h>

#ifndef LIST_H
#define LIST_H

struct ListNode {
    void                (*Destroy)  (struct ListNode* this);
    void*               (*Access)   (struct ListNode* this);
    struct ListNode*    (*Fore)     (struct ListNode* this, size_t distance);
    struct ListNode*    (*Back)     (struct ListNode* this, size_t distance);
    void                (*Append)   (struct ListNode* this, void* source);
    void                (*Prepend)  (struct ListNode* this, void* source);

    void* _inner;
};

struct List {
    void                (*Destroy)      (struct List* this);
    void                (*Foreach)      (struct List* this, void(*action)(void* value, void* closure), void* closure);
    size_t              (*GetLength)    (struct List* this);
    struct ListNode*    (*GetHead)      (struct List* this);
    struct ListNode*    (*GetTail)      (struct List* this);
    void                (*Append)       (struct List* this, void* source);
    void                (*Prepend)      (struct List* this, void* source);

    void* _inner;
};

#endif 