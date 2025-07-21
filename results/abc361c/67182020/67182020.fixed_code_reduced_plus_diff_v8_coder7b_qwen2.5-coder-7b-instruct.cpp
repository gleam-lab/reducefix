#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define coutY cout << "Yes" << endl;
#define coutN cout << "No" << endl;
#define FOR(i,l,r) for(int i=l;i<r;++i)
#define FORrev(i,l,r) for(int i=l;i>r;--i)
#define arrIn(arr, start, N) for (int i = (start); i < (N); ++i) cin >> arr[i];
#define arrOut(arr, start, N) for  (int i = (start); i < (N); ++i) { cout << arr[i] <<" "; } cout << endl;
#define arrCopy(arr1,arr2, start, N) for (int i = (start); i < (N); ++i) arr2[i]= arr1[i];
#define partmax(arr, start, end) *max_element(arr.begin()+start,A.begin()+end);
void yn(bool tf) { cout << (tf ? "Yes\n" : "No\n"); }

//cout << fixed << setprecision(20) <<


int gcd(int a, int b){ //最大公約数
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int lcm(int a, int b){ //最小公倍数
  return a*b / gcd(a, b);
}


int nibun(const std::vector<int>& arr, int key, int begin, int end) {
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  arrIn(A, 0, N);
  
  sort(A.begin(), A.end());

  int ans = INT_MAX;

  for (int i = 0; i <= N - K; ++i) {
    int currentMax = A[i + K - 1];
    int currentMin = A[i];
    ans = min(ans, currentMax - currentMin);
  }

  cout << ans << endl;

  return 0;
}