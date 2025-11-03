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

int main()
{
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
  
  // We are removing exactly K elements
  // So we will keep (N - K) consecutive elements from the sorted array
  // The optimal answer must come from some contiguous subarray of length (N-K)
  int min_diff = INT_MAX;
  int window_size = N - K;
  
  for (int i = 0; i + window_size - 1 < N; i++) {
    chmin(min_diff, A[i + window_size - 1] - A[i]);
  }
  
  cout << min_diff << endl;
  return 0;
}