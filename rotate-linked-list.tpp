class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            int size=1;
            ListNode*cur=head;

            while(cur->next){
                size++;
                cur=cur->next;
            }

            // 1 2 3 | 4 5

            int target=size-k; // 3
            i=1;
            int new_cur=head;

            
            while(new_cur!=nullptr && i<target){
                i++;
                new_cur=new_cur->next;
            }

            ListNode *temp=new_cur->next; //4
            new_cur->next=nullptr;

            cur->next=head;

            return temp;
        }
    };
