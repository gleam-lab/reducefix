#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  // Initialize variables
  vector<char> next = {'R', 'P', 'S'};
  int total = 0;

  // First pass to calculate maximum score starting from each possible initial move
  for (char start : next) {
    int current_score = 0;
    for (int i = 0; i < N; ++i) {
      int score = 0;
      char use = start;
      for (char n : next) {
        if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
          score++;
          use = n;
          break;
        }
      }
      if (score == 0) use = S[i];
      current_score += score;
      next.clear();
      for (auto d : next) {
        if (d != use) next.push_back(d);
      }
    }
    next.clear();
    total = max(total, current_score);
  }

  cout << total << endl;
  return 0;
}