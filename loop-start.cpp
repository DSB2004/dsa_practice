class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode * slow=head;
            ListNode * fast=head;
            
            if (!head || !head->next) {
                    return nullptr;
                }
            
            while(fast&&fast->next){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    break;
                }
            }

            if(slow!=fast){
                return nullptr;
            }

            slow=head;

            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
           
                return slow;
        }
    };