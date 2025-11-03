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

  int ans = A[N-1] - A[0];
  
  // We remove K elements. The remaining sequence has length N-K.
  // We can choose to remove some from the left and some from the right.
  // Try all possible splits: remove i elements from the left, and K-i from the right.
  for (int i = 0; i <= K; i++) {
    int left_removed = i;
    int right_removed = K - i;
    
    // Remaining elements are from index [left_removed] to [N-1-right_removed]
    int l = left_removed;
    int r = N - 1 - right_removed;
    
    if (l <= r) {
      chmin(ans, A[r] - A[l]);
    }
  }

  cout << ans << endl;
  return 0;
}