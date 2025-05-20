class Solution {
    public:
        void deleteNode(ListNode* node) {
            ListNode *cur=node;
            ListNode * next=node->next;
            
            while(next->next!=nullptr){
                cur->val=next->val;
                cur=cur->next;
                next=next->next;
            }
            cur->val=cur->next->val;
            cur->next=nullptr;
        }
        void deleteNode(ListNode* node) {
            node->val=node->next->val;
            node->next=node->next->next;
        }
    };