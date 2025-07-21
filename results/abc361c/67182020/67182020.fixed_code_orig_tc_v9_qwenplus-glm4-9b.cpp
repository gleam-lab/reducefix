#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // Sort the sequence
  sort(A.begin(), A.end());

  // Create a new sequence by removing the largest and smallest K elements
  vector<int> B;
  for (int i = K; i < N-K; i++) {
    B.push_back(A[i]);
  }

  // Find the difference between the maximum and minimum values in B
  int maxB = *max_element(B.begin(), B.end());
  int minB = *min_element(B.begin(), B.end());
  cout << maxB - minB << endl;

  return 0;
}