//
// Created by Suhas Reddy on 2/24/25.
//

class Solution
{
public:
  int candy(vector<int>& ratings)
  {
    int count =0;
    vector<int>candies(ratings.size(), 1);

    for(int i=1;i<ratings.size(); i++)
    {
      if(ratings[i-1]<ratings[i])
        candies[i]=candies[i-1]+1;
    }

    for(int i=ratings.size()-2;i>=0; i--)
    {
      if(ratings[i]>ratings[i+1])
        candies[i]=max(candies[i], candies[i+1]+1);

      count+=candies[i];
    }
    return count+candies[ratings.size()-1];
  }
};