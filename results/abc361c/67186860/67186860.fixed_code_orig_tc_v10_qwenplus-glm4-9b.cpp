#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  // First sort the array
  sort(A.begin(), A.end());
  
  int left = 0;
  int right = n - 1;
  int removedElements = 0;
  while (removedElements < k) {
    if (removedElements % 2 == 0) {
      // Remove from left if it's even
      left++;
    } else {
      // Remove from right if it's odd
      right--;
    }
    removedElements++;
  }
  
  // Now find the minimum possible value of the difference
  int minAnswer = A[right] - A[left];
  cout << minAnswer << endl;
  return 0;
}