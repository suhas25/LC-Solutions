//
// Created by Suhas Reddy on 3/6/25.
//

/*
 * Use a Bidirectional BFS from begin and end word and check the length.
 */

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    //insert all words into set for intermediately generated word lookup.
    unordered_set<string>words (wordList.begin(), wordList.end());

    if(!words.count(endWord))
      return 0;

    //start lookup from begin and end word
    unordered_set<string> begin_set, end_set, next_level;

    begin_set.insert(beginWord);
    end_set.insert(endWord);

    int level=1;

    //Apply BFS
    while(!begin_set.empty() && !end_set.empty())
    {
      //optimization to apply bfs over fewer elements
      if(begin_set.size()>end_set.size())
        swap(begin_set, end_set);

      for(auto word:begin_set)
      {
        for(int i=0;i<word.size(); i++)
        {
          char original_char = word[i];

          for(char ch='a'; ch<='z'; ++ch)
          {
            if(ch==original_char)
              continue;

            word[i]=ch;

            //word already encountered in BFS from end. So, return count
            if(end_set.count(word))
              return level+1;

            if(words.count(word))
            {
              next_level.insert(word);
              words.erase(word);
            }
          }
          word[i]=original_char;
        }
      }
      swap(begin_set, next_level);
      next_level.clear();
      level++;
    }
    return 0;
  }
};