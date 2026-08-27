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
    // get mid of LL 
    // break LL by taking head2 = mid -> next then mid -> next = NULL
    // reverse LL2 
    // compare LL1 & LL2
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast-> next != NULL){
            fast = fast -> next;
            if(fast -> next != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }

    ListNode* reverse(ListNode* prev, ListNode* curr){
        // base case 
        if(curr == NULL){
            return prev;
        }

        // case one
        ListNode * nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;

        // recursive call
        return reverse(prev, curr);
    }

    bool compareLL(ListNode* head, ListNode* head2){
        ListNode* temp = head;
        ListNode* temp2 = head2;

        while(temp != NULL && temp2 != NULL){
            if(temp -> val != temp2 -> val){
                return false;
            }
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        return true;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findmid(head);
        ListNode* head2 = mid -> next;
        // break LL
        mid -> next = NULL;
        
        ListNode* temp = head2; 
        ListNode* prev = NULL;
        ListNode* curr = temp;
        
        head2 = reverse(prev, curr);

        if(compareLL(head, head2)){
            return true;
        }

        return false;

    }
};