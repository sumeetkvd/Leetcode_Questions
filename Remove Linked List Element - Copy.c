Remove Linked List Element: -


The solution in C: -


struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode **pp, *p;

    pp = &head;
    while (*pp) {
        p = *pp;
        if ((*pp)->val == val) { /* found one */
            *pp = p->next;
            free(p);
        } else
            pp = &p->next;
    }

    return head;
}



