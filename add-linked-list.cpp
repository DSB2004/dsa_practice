class Solution {
    public:
    // in memory
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode * head=l1;
            ListNode * prev;
            int carry=0;

            while (l1 != nullptr && l2 != nullptr) {
                int sum = l1->val + l2->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
    
                prev = l1;
                l1 = l1->next;
                l2 = l2->next;
            }

            if(l2!=nullptr){
                prev->next=l2;
                l1=l2;
            }
            
            while(l1!=nullptr){
                int sum =  l2->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
    
                l1->val=node_val;
                prev->next=l1;
                prev=l1;
                l1=l1->next;
            }

            if(carry!=0){
                prev->next=new ListNode(carry);
            }




            return head;
            
           
          
    
        }
       
        
                ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                    ListNode * head=nullptr;
                    ListNode *tail=nullptr;
                    int carry=0;
        
                    while(l1!=nullptr &&l2!=nullptr){
                        int sum=l1->val+l2->val+carry;
                        ListNode * newNode=new ListNode(sum%10);
                        if(head==nullptr){
                            head=newNode;
                        }
                        carry=sum/10;
                        if(tail==nullptr){
                            tail=newNode;
                        }
                        else{
                            tail->next=newNode;
                        }
                        tail=newNode;
                        l1=l1->next;
                        l2=l2->next;
                    }
        
        
                    ListNode * r=(l1==nullptr)?l2:l1;
        
        
                    while(r!=nullptr){
                        int sum=r->val+carry;
                        ListNode * newNode=new ListNode(sum%10);
                        carry=sum/10;
                        tail->next=newNode;          
                        tail=newNode;
                        r=r->next;
                    }
        
                    if(carry>0){
                        tail->next=new ListNode(carry);
                    }
                    return head;
        
                }
            
    };