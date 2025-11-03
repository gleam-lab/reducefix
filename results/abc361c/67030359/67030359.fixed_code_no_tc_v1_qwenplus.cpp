#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vi A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(all(A));

  // We are removing exactly K elements, so we keep (N - K) elements.
  // The optimal strategy is to remove some prefix and/or suffix from the sorted array.
  // Try all possible splits: remove i elements from left and (K-i) from right.
  int ans = A[N - 1] - A[0]; // worst case: no removal benefit

  for (int i = 0; i <= K; i++) {
    int left_removed = i;
    int right_removed = K - i;
    
    // Check if valid
    if (left_removed + right_removed <= N && 
        left_removed < N && right_removed < N) {
      int left_idx = left_removed;
      int right_idx = N - 1 - right_removed;
      
      if (left_idx <= right_idx) {
        chmin(ans, A[right_idx] - A[left_idx]);
      }
    }
  }

  cout << ans << endl;
  return 0;
}