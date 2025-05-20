class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            // intuition to calculate the length of both 
            // arrays and then for larger one remove front node so that both will have same length
            // then compare both till end if intersection found return else null

            int size_a=1;
            int size_b=1;

            ListNode *_a=headA;
            ListNode *_b=headB;

            while(_a->next!=nullptr){
                _a=_a->next;
                size_a++;
            }
            while(_b->next!=nullptr){
                _b=_b->next;
                size_b++;
            }
            int diff = abs(size_a - size_b);
            if (size_a > size_b) {
                for (int i = 0; i < diff; i++) headA = headA->next;
            } else {
                for (int i = 0; i < diff; i++) headB = headB->next;
            }
            while(headA && headB){
                if(headA==headB) return headA;
                headA=headA->next;
                headB=headB->next;
            }
            return nullptr;
        }
    };