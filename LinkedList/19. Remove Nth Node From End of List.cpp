//
// Created by Suhas Reddy on 2/14/25.
//


//second approach is to calculate length and get size()-n+2nd node from start
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    if(head==nullptr)
      return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slowptr=dummy, *fastptr=dummy;

    while(n-->=0)
    {
      fastptr = fastptr->next;
    }

    while(fastptr)
    {
      fastptr=fastptr->next;
      slowptr=slowptr->next;
    }

    slowptr->next = slowptr->next->next;

    return dummy->next;
  }
};