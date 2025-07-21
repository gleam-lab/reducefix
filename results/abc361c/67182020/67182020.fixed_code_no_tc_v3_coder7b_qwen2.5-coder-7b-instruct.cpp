#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  int min_diff = INT_MAX;
  for(int i = 0; i <= N - K - 1; i++) {
    int diff = A[i + K - 1] - A[i];
    if(diff < min_diff) {
      min_diff = diff;
    }
  }

  cout << min_diff << endl;

  return 0;
}