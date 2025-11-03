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
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

using vvi=vector<vi>;
using vvll=vector<vll>;

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T> inline bool chmax(T &a, T b) {
  if (a < b) {
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
  int N,K;
  cin>>N>>K;
  vi A(N);
  for(int i=0;i<N;i++) {
    cin>>A[i];
  }
  sort(all(A));

  // We are going to remove exactly K elements
  // The remaining sequence has length M = N - K
  // We want to minimize (max of remaining - min of remaining)
  
  // Idea: After sorting, the optimal remaining elements must be a contiguous subarray of length M
  // Why? Because if we skip some element in the middle, we can always do better by taking consecutive ones
  
  int M = N - K;
  if (M == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  int ans = A[M-1] - A[0]; // First window
  for (int i = 1; i + M - 1 < N; i++) {
    chmin(ans, A[i + M - 1] - A[i]);
  }
  
  cout << ans << endl;
  return 0;
}