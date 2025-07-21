#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // We use a two-pointer approach to select the K largest elements to be removed
    sort(A.begin(), A.end(), greater<int>()); // Sort in descending order
    
    // We remove the K largest elements from the end
    for (int i = 0; i < K; ++i) {
        A.pop_back();
    }
    
    // After removing the K largest elements, the range [0, A.size() - 1] is the range of elements in B
    int min_value = *min_element(A.begin(), A.end());
    int max_value = *max_element(A.begin(), A.end());
    
    // The result is the difference between the maximum and minimum of B
    cout << max_value - min_value << endl;
    return 0;
}