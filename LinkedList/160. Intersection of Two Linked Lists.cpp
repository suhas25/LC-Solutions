//
// Created by Suhas Reddy on 2/26/25.
//

//O(n+m) time complexity
class Solution
{
  public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    auto pa =headA;
    auto pb = headB;

    while(pa!=pb)
    {
      if(pa==nullptr)
        pa=headB;
      else
        pa=pa->next;

      if(pb==nullptr)
        pb=headA;
      else
        pb=pb->next;
    }
    return pa;
  }
};
