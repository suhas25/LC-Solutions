//
// Created by Suhas Reddy on 3/2/25.
//

//O(N) time and O(1) space complexity.
/*
 * Traverse from right to left and get a maximum digit index. when we find a maximum digit index
 * now, find index smaller than value at maximum digit index onto the left. Now, these two elements needs to be swapped.
 * Lets, say we found a new index with val at index greater than val at maximum digit index previously seen on right.
 * Now, we update maximum digit index, and try to find a value smaller than it onto its left for swap.
 */

class Solution {
public:
  int maximumSwap(int num)
  {
    string numStr = to_string(num);
    int n = numStr.size();
    int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

    // Traverse the string from right to left, tracking the max digit and
    // potential swap
    for (int i = n - 1; i >= 0; --i)
    {
      if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex])
      {
        maxDigitIndex = i;  // Update the index of the max digit
      }

      if (numStr[i] < numStr[maxDigitIndex])
      {
        swapIdx1 = i;  // Mark the smaller digit for swapping
        swapIdx2 = maxDigitIndex;  // Mark the larger digit for swapping
      }
    }

    // Perform the swap if a valid swap is found
    if (swapIdx1 != -1 && swapIdx2 != -1)
    {
      swap(numStr[swapIdx1], numStr[swapIdx2]);
    }

    return stoi(numStr);  // Return the new number or the original if no
                         // swap occurred
  }
};