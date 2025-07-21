#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend()); // Sort the array in descending order
  deque<int> dq(A.begin(), A.begin() + K); // Take first K elements

  // Remove the K largest elements
  for (int i = 0; i < N - K; i++) {
    A[i] = A[i + K];
  }
  A.erase(A.begin() + N - K, A.end()); // Remove the K largest elements

  // Calculate the minimum possible value of the difference
  int max_val = *max_element(A.begin(), A.end());
  int min_val = *min_element(A.begin(), A.end());
  cout << max_val - min_val << endl;
  return 0;
}