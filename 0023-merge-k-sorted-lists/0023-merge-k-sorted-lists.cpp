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
    // ListNode* convert_arr_to_LL(vector<int>& res){
    //     int n = res.size();
    //     if(n==0){
    //         return nullptr;
    //     }
    //     ListNode* head = new ListNode(res[0]);
    //     ListNode* cur = head;
    //     for(int i=1;i<n;i++){
    //         ListNode* temp = new ListNode(res[i]);
    //         cur->next = temp ;
    //         cur = cur->next;
    //     }
    //     return head;
    // }
    
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
        // vector<int> res;
        // for(int i=0;i<lists.size();i++){
        //     ListNode* temp = lists[i];
        //     while(temp != nullptr){
        //         res.push_back(temp->val);
        //         temp = temp->next;
        //     }
        // }
        // sort(res.begin(),res.end());
        // ListNode* head = convert_arr_to_LL(res);

        // return head;

    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>>pq ;
        int k = lists.size();
        if(k==0) return nullptr ;
        for(int i=0;i<k;i++){
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy ;

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            cur->next = x.second ;
            cur = cur->next ;

            if(x.second->next){
                pq.push({x.second->next->val,x.second->next});
            }
        }
        return dummy->next;
    }
};
