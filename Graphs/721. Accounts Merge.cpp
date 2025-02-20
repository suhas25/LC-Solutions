//
// Created by Suhas Reddy on 2/19/25.
//


/*
Build adjacencylist and do a DFS and merge accounts.
*/

// k emails N persons
//Time complexity - O(NKlogNK)   Space Complexity - O(NK)
class Solution
{
public:
  unordered_map<string, vector<string>>adjList;
  unordered_set<string>visited;

  void DFS(vector<string >&merged_account, string primary_email)
  {
    visited.insert(primary_email);
    merged_account.push_back(primary_email);

    for(auto email:adjList[primary_email])
    {
      if(!visited.count(email))
        DFS(merged_account,email);
    }
  }

  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
  {
    //Build adjacency list based on first email of every account.
    for(const auto& account:accounts)
    {
      int size = account.size();

      auto primary_email = account[1];

      for(int j=2;j<size; j++)
      {
        auto email = account[j];
        adjList[primary_email].push_back(email);
        adjList[email].push_back(primary_email);
      }
    }

    vector<vector<string>>merged_accounts;

    for(const auto&account:accounts)
    {
      auto name = account[0];
      auto primary_email = account[1];

      if(!visited.count(primary_email))
      {
        vector<string>merged_account;

        merged_account.push_back(name);
        DFS(merged_account, primary_email);
        sort(merged_account.begin()+1, merged_account.end());
        merged_accounts.push_back(merged_account);
      }
    }
    return merged_accounts;
  }
};
