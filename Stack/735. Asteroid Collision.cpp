//
// Created by Suhas Reddy on 2/21/25.
//

/*
 * when you encounter a negative asteroid and stack is not empty and stack top contains positive element.
 * then they are set to collide.
 * case 1: if collision results in exploding, then we remove top ele from stack and dont add current negative ele to stack setting it to zero.
 * case 2: collision resulting in negative value. we pop back and continue colliding with top elements on stack top
 * case 3: collision resulting in positive value. we set negative number to zero and dont add it to stack.
 * */

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids)
  {
    vector<int>stk;

    for(auto asteroid:asteroids)
    {
      while(asteroid<0 && !stk.empty() && stk.back()>0)
      {
        int diff = asteroid+stk.back();

        if(diff>0)
        {
          asteroid=0; //when positive one is bigger, then we dont add this one.
        }
        else if(diff<0) //when negative asteroid is bigger
        {
          stk.pop_back(); // then we remove the positive one
        }
        else //when both asteroids are of same weight they explode.
        {
          asteroid=0;
          stk.pop_back();
        }
      }

      if(asteroid!=0)
        stk.push_back(asteroid);
    }
    return stk;
  }
};