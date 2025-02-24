//
// Created by Suhas Reddy on 2/22/25.
//

class Solution {
public:
  vector<int> getRow(int rowIndex)
  {

    vector<int>temp(1, 1);

    for(int i=1;i<rowIndex+1; i++)
    {
      vector<int>row(i+1, 1);
      auto prev_row =temp;

      for(int j=1;j<i; j++)
      {
        row[j]=(prev_row[j-1]+ prev_row[j]);
      }
      temp=row;
    }
    return temp;
  }
};