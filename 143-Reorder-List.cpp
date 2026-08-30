/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode * next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        // find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL and fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // at this point slow at middle
        ListNode* nexttomiddle = reverse(slow->next);
        slow -> next = NULL;

        // merge logic
        ListNode* first = head;
        ListNode* second = nexttomiddle;

        while(second != NULL) {
            ListNode* firstnext = first -> next;
            ListNode* secondnext = second -> next;

            // merge
            first -> next = second;
            second -> next = firstnext;

            first = firstnext;
            second = secondnext;
        }
    }
};