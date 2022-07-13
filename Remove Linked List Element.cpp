Remove Linked List Element: -


The solution in CPP: -


class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    ListNode* removeElements(ListNode* head, int val) {
        while((head != nullptr) && (head->val == val))
            head = head->next;
        ListNode *temp = head;
        while(temp != nullptr){
            ListNode *next = temp->next;
            while((next != nullptr) && (next->val == val)){
                temp->next = next->next;
                next = next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};



