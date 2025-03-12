//
// Created by Suhas Reddy on 3/8/25.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

class WordStreamProcessor
{
  private:
  unordered_map<string, int> wordCount; // Stores word frequencies
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> minHeap; // Min-heap for top N words
  int topN; // Number of top words to track

  public:
  WordStreamProcessor(int N) : topN(N) {}

  // Process a single sentence (real-time input)
  void processSentence(const string& sentence)
  {
    stringstream ss(sentence);
    string word;
    bool heapUpdated = false;

    while (ss >> word)
    {
      word = sanitizeWord(word);

      if (!word.empty())
      {
        wordCount[word]++;

        // If heap is not full, just add the word
        if (minHeap.size() < topN)
        {
          minHeap.push({wordCount[word], word});
          heapUpdated = true;
        }
        else
        {
          // If the new frequency is greater than the min element, update the heap
          if (wordCount[word] > minHeap.top().first)
          {
            minHeap.pop(); // Remove the least frequent word
            minHeap.push({wordCount[word], word});
            heapUpdated = true;
          }
        }
      }
    }

    if (heapUpdated) {
      displayTopNWords();
    }
  }

  // Function to clean words (remove punctuation, convert to lowercase)
  string sanitizeWord(string word)
  {
    string cleanWord;
    for (char c : word)
    {
      if (isalpha(c)) // Keep only alphabetic characters
        cleanWord += tolower(c);
    }
    return cleanWord;
  }

  // Display top N words dynamically
  void displayTopNWords()
  {
    vector<pair<int, string>> topWords;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> tempHeap = minHeap;

    while (!tempHeap.empty())
    {
      topWords.push_back(tempHeap.top());
      tempHeap.pop();
    }

    reverse(topWords.begin(), topWords.end()); // Sort in descending order
    cout << "Updated Top " << topN << " Words:" << endl;
    for (auto& word : topWords)
      cout << word.second << " - " << word.first << " occurrences" << endl;
    cout << "--------------------------------" << endl;
  }

  // Simulate real-time processing from a stream
  void processStream()
  {
    vector<string> sentences = {
        "The quick brown fox jumps over the lazy dog.",
        "The fox is quick and the dog is lazy.",
        "The fox and the dog became friends.",
        "The dog barks, and the fox runs away.",
        "The quick fox runs through the forest."
    };

    for (const auto& sentence : sentences)
    {
      processSentence(sentence); // Process incoming sentence
      this_thread::sleep_for(chrono::seconds(1)); // Simulate streaming delay
    }
  }
};

int main()
{
  WordStreamProcessor processor(3); // Track top 3 words in real-time
  processor.processStream(); // Start processing incoming sentences
  return 0;
}

