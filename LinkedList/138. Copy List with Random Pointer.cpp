//
// Created by Suhas Reddy on 3/2/25.
//

//using O(n) time and O(1) space complexity
class Solution {
public:
  Node* copyRandomList(Node* head)
  {
    if(head == NULL)
      return NULL;

    /*
    1. Clone new nodes
    2. Copy random pointers
    3. Interleave list
    */

    //step 1
    auto temp = head;
    while(temp!=NULL)
    {
      Node* newNode = new Node(temp->val);
      newNode->next = temp->next;
      temp->next = newNode;
      temp = temp->next->next;
    }

    //step 2
    temp = head;
    while(temp)
    {
      if(temp->random==NULL)
        temp->next->random =NULL;
      else
        temp->next->random = temp->random->next;
      temp = temp->next->next;
    }

    Node* oldhead = head;
    Node* newheadref= head->next;

    auto newhead = newheadref;

    //STEP 3
    while(oldhead)
    {
      oldhead->next = oldhead->next->next;
      oldhead = oldhead->next;

      newhead->next = (newhead->next!=NULL)?newhead->next->next:NULL;
      newhead=newhead->next;

    }
    return newheadref;
  }
};

//Using O(n) extra space.
class Solution2
{
public:
  Node* copyRandomList(Node* head)
  {
    std::unordered_map<Node*, Node*> old_to_new;

    auto curr = head;
    while (curr != nullptr)
    {
      old_to_new[curr] = new Node(curr->val);
      curr = curr->next;
    }

    curr = head;
    while (curr != nullptr)
    {
      old_to_new[curr]->next = old_to_new[curr->next];
      old_to_new[curr]->random = old_to_new[curr->random];
      curr = curr->next;
    }

    return old_to_new[head];
  }
};