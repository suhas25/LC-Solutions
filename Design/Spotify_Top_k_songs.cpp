//
// Created by Suhas Reddy on 3/9/25.
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;

class Playlist {
private:
  list<string> recentSongs;  // Stores recently played songs in order
  unordered_map<string, list<string>::iterator> songMap;  // Fast lookup for song presence
  unordered_map<string, pair<int, time_t>> songFrequency;  // Tracks play count & last played timestamp

  // Min-Heap to store top K most played songs
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> minHeap;
  int maxK;  // Max number of songs to track

  const int SEVEN_DAYS = 7 * 24 * 60 * 60;  // 7 days in seconds

public:
  // Constructor to define max K songs to track
  Playlist(int k) {
    maxK = k;
  }

  // Add or update a song in the playlist
  void addSong(const string& songName) {
    time_t currentTime = time(0);  // Get current timestamp

    // If the song is new, add it to recentSongs
    if (songMap.find(songName) == songMap.end()) {
      recentSongs.push_front(songName);  // Insert at front (most recent)
      songMap[songName] = recentSongs.begin();
    }

    // Increment the frequency count and update last played time
    songFrequency[songName] = {songFrequency[songName].first + 1, currentTime};

    // Update the heap to maintain top K most played songs
    updateHeap();
  }

  // Get a song if it exists
  string getSong(const string& songName) {
    if (songMap.find(songName) != songMap.end()) {
      return songName;
    }
    return "Song not found";
  }

  // Remove songs that haven't been played in the last 7 days
  void cleanOldSongs() {
    time_t currentTime = time(0);

    for (auto it = recentSongs.begin(); it != recentSongs.end();) {
      string song = *it;
      if (currentTime - songFrequency[song].second > SEVEN_DAYS) {
        // Remove song from all data structures
        songMap.erase(song);
        songFrequency.erase(song);
        it = recentSongs.erase(it);
      } else {
        ++it;
      }
    }

    // Update heap after cleanup
    updateHeap();
  }

  // Maintain Top K Songs Using Min-Heap (Updated Dynamically)
  void updateHeap() {
    // Temporary heap to store updated frequencies
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> tempHeap;

    // Iterate through song frequencies and maintain a min-heap of size K
    for (const auto& entry : songFrequency) {
      tempHeap.push({entry.second.first, entry.first});
      if (tempHeap.size() > maxK) {
        tempHeap.pop(); // Remove least played song
      }
    }

    // Assign the updated heap to the global min-heap
    minHeap = move(tempHeap);
  }

  // Retrieve the top K most played songs in O(K)
  vector<string> getMostPlayed() {
    vector<string> mostPlayedSongs;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> tempHeap = minHeap;

    while (!tempHeap.empty()) {
      mostPlayedSongs.push_back(tempHeap.top().second);
      tempHeap.pop();
    }

    reverse(mostPlayedSongs.begin(), mostPlayedSongs.end()); // Sort in descending order
    return mostPlayedSongs;
  }

  // Display the playlist
  void displayPlaylist() {
    cout << "Recently Played Songs: ";
    for (const string& song : recentSongs) {
      cout << song << " | ";
    }
    cout << endl;
  }
};

int main() {
  Playlist myPlaylist(3);  // Track top 3 songs

  // Simulating song plays
  myPlaylist.addSong("Shape of You");
  myPlaylist.addSong("Blinding Lights");
  myPlaylist.addSong("Levitating");
  myPlaylist.addSong("Shape of You");
  myPlaylist.addSong("Levitating");
  myPlaylist.addSong("Levitating");
  myPlaylist.addSong("Hello");

  myPlaylist.displayPlaylist();

  // Simulating the removal of old songs
  myPlaylist.cleanOldSongs();

  // Get the top 3 most played songs
  vector<string> topSongs = myPlaylist.getMostPlayed();
  cout << "Top 3 Most Played Songs: ";
  for (const string& song : topSongs) {
    cout << song << " | ";
  }
  cout << endl;

  return 0;
}
