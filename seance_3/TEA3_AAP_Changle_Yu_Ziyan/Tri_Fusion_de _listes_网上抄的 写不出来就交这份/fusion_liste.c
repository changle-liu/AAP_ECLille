#include "fusion_liste.h"

ListNode *mergeSortedList(ListNode *L1, ListNode *L2){
    ListNode dummy(-1), *p1 = &dummy, *p2 = L2;
    dummy.next = L1;
    while(p1->next != NULL && p2 != NULL){
        if(p1->next->value >= p2->value){
            L2 = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = L2;
        }
        else{
            p1 = p1->next;
        }
    }
    if(p1->next == NULL){
        p1->next = p2;
    }

    return dummy.next;
}

ListNode *listMergeSort(ListNode *head)
{
    if(head == NULL || head->next == NULL) 
        return head;

    ListNode *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *leftHead = head, *rightHead = slow->next;
    slow->next = NULL;    

    leftHead  = listMergeSort(leftHead);
    rightHead = listMergeSort(rightHead);

    return mergeSortedList(leftHead, rightHead);
}
