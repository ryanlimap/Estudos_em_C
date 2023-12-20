//código de lista encadeada da prova 1 substitutiva
ListNode* search_previous(List l, int v) {
    ListNode *p = l->first;

    if(p == NULL) {
        return NULL;
    }
    while(p->next != NULL) {
        if(p->next == v) {
            return p
        }
        else if {
            p = p->next;
        }
    }    
}