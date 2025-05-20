class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *head=nullptr;
            ListNode *tail=nullptr;
            if(list1==nullptr){
                return list2;
            }
            if(list2==nullptr){
                return list1;
            }
            // first select the head node 

            // 1 2 4 
            // 1 3 5 

            if(list1->val>list2->val){
                head=list2;
                tail=list2;
                list2=list2->next;
            }
            else{
                head=list1;
                tail=list1;
                list1=list1->next;
            }

            while(list1!=nullptr &&list2!=nullptr){
                if(list1->val>list2->val){
                    tail->next=list2;
                    tail=list2;
                    list2=list2->next;
                }
                else{
                    tail->next=list1;
                    tail=list1;
                    list1=list1->next;
                }
            }
            while(list1!=nullptr){
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }
            while(list2!=nullptr){
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
            return head;
        }
    };