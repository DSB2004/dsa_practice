class Solution {
public:
    ListNode* helper(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* stop = end->next;

        while (curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* start = head;
        ListNode* end = head;

        while (true) {
            for (int i = 1; i < k && end; ++i) {
                end = end->next;
            }

            if (!end) break;

            ListNode* nextGroupHead = end->next;
            ListNode* newHead = helper(start, end);

            prev->next = newHead;
            start->next = nextGroupHead;
            
            prev = start;
            start = nextGroupHead;
            end = nextGroupHead;
        }

        return dummy.next;
    }
};
