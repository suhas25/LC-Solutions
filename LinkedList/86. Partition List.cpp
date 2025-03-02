//
// Created by Suhas Reddy on 2/25/25.
//

class Solution {
public:
  ListNode* partition(ListNode* head, int x)
  {
    auto before_head = new ListNode(0);
    auto before = before_head;

    auto after_head = new ListNode(0);
    auto after = after_head;

    while(head!=nullptr)
    {
      if(head->val<x)
      {
        before->next = head;
        before = before->next;
      }
      else
      {
        after->next = head;
        after= after->next;
      }
      head=head->next;
    }

    after->next=nullptr;
    before->next = after_head->next;

    return before_head->next;
  }
};
