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
    ListNode* getKth(ListNode* cur, int k){
        int count = 0 ;
        while(cur && count != k-1){
            count++;
            cur = cur->next;
        }
        if(count == k-1)
            return cur ;
        else 
            return nullptr;
    }
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr ;
        ListNode* front ;

        while(cur){
            front = cur->next;
            cur->next = prev ;
            prev = cur ;
            cur = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next ;

        while(cur){
            ListNode* kth = getKth(cur,k);
            if(kth){
                ListNode* next = kth->next;
                kth->next = nullptr;
                reverse(cur);

                if(cur == head){
                    head = kth;
                }else{
                    prev->next = kth;
                }
                prev = cur ;
                cur = next;
            }
            else{
                if(prev){
                    prev->next = cur;
                    break;
                }
                prev = cur;
                cur = next;
            }
        }
        return head;
    }
};