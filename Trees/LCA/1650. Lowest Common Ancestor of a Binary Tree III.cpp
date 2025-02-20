//
// Created by Suhas Reddy on 2/17/25.
//

// Here we have parent pointers in node structures


//O(n) time and O(1) space complexity
class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q)
  {
    auto a=p, b=q;

    //we are covering a distance (p->root + q->root) from p and q
    // by assigning q to p and p to q once we encounter nullptr(parent of root).
    // Then we end up at LCA.
    while(a!=b)
    {
      a=a->parent;
      if(a==nullptr)
        a=q;

      b=b->parent;
      if(b==nullptr)
        b=p;
    }
    return a;
  }
};


//O(n) time and space complexity
class Solution2 {
public:
  Node* lowestCommonAncestor(Node* p, Node * q)
  {
    unordered_set<Node*>nodeset;

    while(p)
    {
      nodeset.insert(p);
      p=p->parent;
    }

    while(q)
    {
      if(nodeset.count(q))
        return q;
      q=q->parent;
    }

    return nullptr;
  }
};
