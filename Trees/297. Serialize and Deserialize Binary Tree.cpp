//
// Created by Suhas Reddy on 2/15/25.
//


/*
 * Serialise using "#val or #NULL
 * Deserialize and write to vector<strings> by splitting based on # values
 * now perform bfs based on queue and vector indexes.
 * */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root)
  {
    std::string result = "";

    if (root == nullptr)
    {
      result += "NULL";
      return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
      auto ele = q.front();
      q.pop();

      if (ele == NULL)
        result += "#NULL";

      else
      {
        result+= "#" + to_string(ele->val);

        q.push(ele->left);
        q.push(ele->right);
      }
    }
    return result;
  }

  TreeNode* deserialize_helper(vector<string>& v)
  {
    if(v[0]=="NULL")
      return NULL;

    TreeNode* root = new TreeNode(stoi(v[0]));

    queue<TreeNode*>q;
    q.push(root);

    int index=1;
    while(index<v.size())
    {
      auto curr = q.front();
      q.pop();

      if(v[index]!="NULL")
      {
        curr->left = new TreeNode(stoi(v[index]));
        q.push(curr->left);
      }
      index++;

      if(v[index]!="NULL")
      {
        curr->right = new TreeNode(stoi(v[index]));
        q.push(curr->right);
      }
      index++;
    }
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data)
  {
    std::string temp;
    vector<string> nodes;

    for (int i = 0; i < data.size(); i++)
    {
      if (data[i] != '#')
        temp += data[i];
      else
      {
        if (!temp.empty()) // to fix case where we have "#" before root node
          nodes.push_back(temp);
        temp = "";
      }
    }

    if (temp.size() != 0) //push all found element (NULL)
      nodes.push_back(temp);

    return deserialize_helper(nodes);
  }
};

