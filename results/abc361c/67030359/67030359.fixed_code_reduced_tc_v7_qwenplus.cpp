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
  // The remaining elements will be a contiguous block in the sorted array?
  // Actually: we can choose any K elements to remove. But since we want to minimize (max - min),
  // it's optimal to keep a contiguous segment of length (N-K) in the sorted array.
  // Why? Because if we skip some element inside the range, we could potentially reduce the range by including a closer one.

  int remain = N - K;
  int ans = INT_MAX;

  // Try all possible contiguous segments of length 'remain' in the sorted array
  for (int i = 0; i + remain - 1 < N; i++) {
    chmin(ans, A[i + remain - 1] - A[i]);
  }

  cout << ans << endl;
  return 0;
}