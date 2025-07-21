#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T, N, K;
  cin >> T;

  while (T--) {
    cin >> N >> K;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }

    // Sort the sequences based on A_i values
    sort(A.begin(), A.end());

    int min_result = INT_MAX;
    int sum_B = 0;
    int pointer_B = 0;

    // Iterate over the sorted sequence A
    for (int i = 0; i < N; i++) {
      sum_B += B[pointer_B]; // Add the current B_i value

      if (i >= K - 1) { // If we have already considered K-1 B_i values
        min_result = min(min_result, A[i] * sum_B);
        sum_B -= B[pointer_B]; // Remove the B_i value that is no longer considered

        pointer_B++; // Move to the next B_i value
      }
    }

    cout << min_result << endl;
  }

  return 0;
}