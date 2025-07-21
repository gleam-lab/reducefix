#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define mp make_pair
#define eb emplace_back

using namespace std;

using ll = long long int;
using vi = vector<int>;

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> A(N); // {value, original_index}
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }

  // Sort by value
  sort(all(A));

  int min_diff = numeric_limits<int>::max();

  // We need to pick N - K elements such that they are in order
  // Try all windows of size N - K and check if indices are increasing
  int window_size = N - K;
  for (int i = 0; i + window_size <= N; ++i) {
    vector<pair<int, int>> window(A.begin() + i, A.begin() + i + window_size);

    // Check if the original indices are in increasing order
    sort(window.begin(), window.end([](const pair<int,int>& a, const pair<int,int>& b) {
      return a.second < b.second;
    });

    bool valid = true;
    for (int j = 1; j < window.size(); ++j) {
      if (window[j].second < window[j-1].second) {
        valid = false;
        break;
      }
    }

    if (valid) {
      chmin(min_diff, window.back().first - window.front().first);
    }
  }

  cout << min_diff << endl;
  return 0;
}