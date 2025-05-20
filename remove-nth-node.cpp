class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // calculate the size of linked list

            // 1->2->3->4->5   :5   :2 -> 3 index
             
            int size=0;

            ListNode * cur=head;
            while(cur!=nullptr){
                size++;
                cur=cur->next;
            }
            int index=0;
            cur=head;

            // edge case
            if(size==1 &&n==1){
                return nullptr;
            }
            while(index<(size-n-1)){

                cur=cur->next;
                index++;
            }

            // head node
            if(size==n){
                return head->next;

            }
            // middle node
            if(cur->next->next!=nullptr){

                cur->next=cur->next->next;
            }
            // tail node
            else{
                cur->next=nullptr;
            }

            return head;
        }
    };