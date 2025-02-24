//
// Created by Suhas Reddy on 2/21/25.
//

/*
- create a new string and append "/" to it so that the last encountered curr_string after last "/" in path is validated and pushed to stack if valid.
- Ideally break the string on encountering a "/".

on encountering a "/"
    case 1:- if we have curr as ".." we need to remove one level up (only if stack is not empty)
    case 2: curr is empty, then ignore it.
               case 3: curr is ".", then ignore it
    case 4: when the case is not covered in last 3, then push it to stack.
push the current string formed until that moment into stack.

 */

class Solution {
public:
  string simplifyPath(string path)
  {
    vector<string>stk;
    string curr_string;

    string temp_path = path+"/";

    for(int i=0;i<temp_path.size(); i++)
    {
      char ch = temp_path[i];
      if(ch=='/')
      {
        if(curr_string=="..")
        {
          if(!stk.empty())
            stk.pop_back();

          curr_string="";
          continue;
        }

        //ignore it. as question says path must not have "." and ".."
        else if (curr_string=="" || curr_string==".")
        {
          curr_string="";
          continue;
        }
        else
          stk.push_back(curr_string);
        curr_string="";
      }
      else
      {
        curr_string+=temp_path.substr(i, 1);
      }
    }

  string result;
  for(auto str:stk)
  {
    result+="/"+str;
  }

    return (result.empty())?"/":result;
  }
};
