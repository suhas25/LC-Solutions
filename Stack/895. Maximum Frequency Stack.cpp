//
// Created by Suhas Reddy on 2/21/25.
//

/*
 * while pushing
 * 1. update max_freq
 * 2. update freq_map by incrementing counter
 * 3. insert value to stack
 *
 * while popping
 * 1. get value to pop from max_freq stack top
 * 2. update freq_map by decrementing counter
 * 3. update max_freq if max_freq stack is empty
 * 4. return value
 * */

class FreqStack {
public:
  int max_freq;

  // frequency ->ele
  map<int, int> freq_map;

  //{frequency ->stack of values matching that frequency}
  unordered_map<int, stack<int>> stacks;
  FreqStack()
  {

  }

  void push(int val)
  {
    freq_map[val]++;

    auto freq=freq_map[val];
    max_freq=max(max_freq, freq);

    stacks[freq].push(val);
  }

  int pop()
  {
    auto val = stacks[max_freq].top();stacks[max_freq].pop();
    freq_map[val]--;
    if(stacks[max_freq].empty())
      max_freq--;
    return val;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */