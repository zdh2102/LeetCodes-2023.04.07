#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int arr[], int n) {
    if (n <= 0) {
        return NULL;
    }
    struct ListNode *head = NULL, *p = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if(head == NULL){
            head = node;
        }else{
            p->next = node;
        }
        p = node;
    }
    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL) {
        return NULL;
    }
    struct ListNode*p = head;
    struct ListNode*q, *r;
    while(p) {
        q = p->next;
        r = p;
        while(q) {
            if(p->val == q->val) {
                r->next = q->next;
                free(q);
                q = r->next;
            } else {
                q = q->next;
                r = r->next;
            }
        }
        p = p->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(int);
    struct ListNode* head = createList(arr, n);
    printf("Original List: ");
    printList(head);
    head = deleteDuplicates(head);
    printf("List after removing duplicates: ");
    printList(head);
    return 0;
}