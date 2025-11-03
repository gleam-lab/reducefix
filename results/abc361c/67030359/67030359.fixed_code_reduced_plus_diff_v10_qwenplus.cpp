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
  // So we will keep M = N - K elements
  int M = N - K;
  int ans = INT_MAX;
  
  // Try all possible contiguous segments of length M in the sorted array
  // because the optimal remaining sequence must be a contiguous block in sorted order
  for (int i = 0; i + M - 1 < N; i++) {
    chmin(ans, A[i + M - 1] - A[i]);
  }
  
  cout << ans << endl;
  return 0;
}