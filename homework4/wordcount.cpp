#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// iterate through std input
int main () {
  string word;
  vector<string> wordArray;
  while (std::cin >> word) {
    std::transform (word.begin(), word.end(), word.begin(), ::tolower);
    std::replace_if(word.begin(), word.end(), ::ispunct, ' ');
    wordArray.push_back(word);
  }
  sort(wordArray.begin(), wordArray.end());
  int size = wordArray.size();

  int count = 0;
  word = wordArray[0];

  for (int i = 0; i < size; i++) {
    if (word != wordArray[i]) {
      cout << word << ' ' << count << endl;
      count = 0;
      word = wordArray[i];
      }
    count ++;
  }
  cout << word << ' ' << count << endl;
}
