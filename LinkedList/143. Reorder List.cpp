//
// Created by Suhas Reddy on 2/15/25.
//

//commute to mid of list and reverse second half. then join the nodes alternatively once each from first and second half.
class Solution
{
public:
  void reorderList(ListNode* head)
  {
    //this approach leaves slow ptr at mid of list.
    auto slow = head, fast = head;

    while(fast!=nullptr && fast->next!=nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    //now reverse the second half in place
    auto second_half_start = slow;
    auto curr = second_half_start;
    ListNode* prev = nullptr;

    while(curr)
    {
      auto actual_next = curr->next;
      curr->next = prev;
      prev=curr;
      curr=actual_next;
    }

    //now join the nodes
    auto first = head; //first half start
    auto second = prev; //second half start

    //do second->next instead of second as we are checking second->next in loop
    while(second->next)
    {
      auto first_actual_next = first->next;
      auto second_actual_next = second->next;

      first->next = second;
      second->next = first_actual_next;

      first = first_actual_next;
      second = second_actual_next;
    }

    return;
  }
};