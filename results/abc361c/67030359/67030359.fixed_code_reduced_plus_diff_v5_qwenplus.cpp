#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

using namespace std;

using ll=long long int;
using vi=vector<int>;

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
  vi A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  sort(all(A));
  
  // We need to remove exactly K elements, so we keep (N-K) elements.
  // The remaining elements must be contiguous in the sorted array to minimize range.
  // Try all possible contiguous subarrays of length (N-K)
  int min_range = INT_MAX;
  int window_size = N - K;
  
  for (int i = 0; i + window_size - 1 < N; i++) {
    chmin(min_range, A[i + window_size - 1] - A[i]);
  }
  
  cout << min_range << endl;
  return 0;
}