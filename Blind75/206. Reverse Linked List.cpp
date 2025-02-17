//
// Created by Suhas Reddy on 2/15/25.
//

//Iterative solution - O(1) space complexity
class Solution
{
public:
  ListNode* reverseList(ListNode* head)
  {
    if(head==nullptr)
      return head;

    //use two pointers for iterating through
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr)
    {
      auto original_next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = original_next;
    }
    return prev;
  }
};

//Recursive solution O(n) time and space complexity
class Solution2 {
public:
  ListNode* reverseList(ListNode* head)
  {
    if(head==nullptr)
      return head;

    ListNode* newhead = head;

    if(head->next)
    {
      newhead = reverseList(head->next);
      head->next->next = head;
    }
    head->next = nullptr;

    return newhead;
  }
};