struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow=head;
        ListNode * fast=head;

        while(fast!=nullptr && fast->next!==nullptr){
            slow=slow->next;
            fast=falst->next->next;
        }
        return slow;
    }
};