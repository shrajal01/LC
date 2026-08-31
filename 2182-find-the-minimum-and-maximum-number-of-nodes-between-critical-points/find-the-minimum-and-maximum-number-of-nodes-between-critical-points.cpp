class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 1, first = -1, last = -1, mn = INT_MAX;

        for (auto p = head, q = head->next; q->next; p = q, q = q->next, i++) {
            if ((q->val > p->val && q->val > q->next->val) ||
                (q->val < p->val && q->val < q->next->val)) {
                
                if (first != -1) mn = min(mn, i - last);
                else first = i;
                
                last = i;
            }
        }

        if (first == last) return {-1, -1};
        return {mn, last - first};
    }
};