/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* get_right(struct ListNode* head, int cnt)
{
    struct ListNode* right = NULL;
    if (cnt == 1) {
        right = head->next;
        return right;
    }
    for (int i = 0; i < cnt; i++) {
        if (i == 0) {
            right = head->next;
        } else {
            right = right->next;
        }
    }
    return right;
}

struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL)
        return NULL;

    struct ListNode *temp = head->next;
    struct ListNode *right = head;
    int cnt = 0;
    while (temp) {
        struct ListNode *check = head;
        struct ListNode *check_pre = NULL;
        cnt++;
        while (check != temp) {
            if (check->val > temp->val) {
                right->next = temp->next;
                temp->next = check;
                if (check == head) {
                    head = temp;
                }
                if (check_pre) {
                    check_pre->next = temp;
                }
                break;
            } else {
                check_pre = check;
                check = check->next;
            }
        } 
        right = get_right(head, cnt);
        if (right == NULL) {
            break;
        }   
        temp = right->next;
    }
    return head;
}