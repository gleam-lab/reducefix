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
  
  // We need to remove exactly K elements
  // The remaining elements form a contiguous subarray in the sorted array
  // because we want to minimize (max - min), so we should keep values close together
  
  int ans = INT_MAX;
  // Try all possible windows of length (N - K) in the sorted array
  for (int i = 0; i + (N - K) - 1 < N; i++) {
    int j = i + (N - K) - 1;
    chmin(ans, A[j] - A[i]);
  }
  
  cout << ans << endl;
  return 0;
}