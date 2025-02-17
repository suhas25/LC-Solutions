//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  bool hasCycle(ListNode* head)
  {
    if (head == nullptr)
      return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast!= nullptr && fast->next!=nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;

      if(fast==slow)
        return true;
    }
    return false;
  }
};
