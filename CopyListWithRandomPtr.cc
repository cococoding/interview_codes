// http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return NULL;
        RandomListNode *p = head, *q = NULL, *new_head = NULL;
        while(p) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = p->next;
        }
        p = head;
        while(p) {
            if (p->random)
                p->next->random = p->random->next;
            else
                p->next->random = NULL;
            p = p->next;
        }
        new_head = head->next;
        p = head;
        while(p) {
            q = p->next;
            p->next = q->next;
            q->next = p->next->next;
            p = p->next;
        }
        return new_head;
    }
};
