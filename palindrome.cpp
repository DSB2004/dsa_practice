class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            // first reversing the list 


            // HEAD: 1->2->2->1

            
            
            ListNode *slow=head;
            ListNode *fast=head;
            
            while(fast!=nullptr && fast->next!=nullptr){
                slow=slow->next;
                fast=fast->next->next;
            }


            ListNode *prev=nullptr;
            ListNode *nextNode=nullptr;
            ListNode * cur=slow;
            

            while(cur!=nullptr){
                nextNode=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nextNode;
            }

            // HEAD: 1->2->2->1

            while(prev!=nullptr &&head!=nullptr){
                if(prev->val!=head->val){
                    return false;
                }
                prev=prev->next;
                head=head->next;
            }
            return true;
        }
    };