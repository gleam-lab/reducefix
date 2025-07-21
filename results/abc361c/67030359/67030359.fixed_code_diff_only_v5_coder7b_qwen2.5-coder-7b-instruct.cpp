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

struct pnt {
  ll x;
  ll y;
};

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

  // The goal is to minimize the difference between max and min values of the resulting array
  // By removing K elements, we can effectively reduce the range of the array
  // To minimize the range, we should ideally keep the smallest and largest elements together
  // This way, the removal of any K elements will not significantly affect the range

  // Since the array is sorted, the smallest element is at index 0 and the largest element is at index N-1
  // We need to decide whether to remove elements from the start or end to minimize the range
  // Removing elements from the end will give us a smaller range because the gap between the smallest and largest elements decreases more rapidly

  // Calculate the potential range after removing K elements from the end
  int result = A[N-K-1] - A[0];

  cout << result << endl;
  return 0;
}