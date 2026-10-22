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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            n++;
            curr = curr->next;
        }
        k = k % n;
        while(k--){
            ListNode* temp = head;
            ListNode* prev = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            while(prev->next != temp){
                prev = prev->next;
            }
            temp->next = head;
            prev->next = nullptr;
            head = temp;

        }
        return head;
    }
};