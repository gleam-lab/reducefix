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
    
    sort(A.begin(), A.end());
    
    vector<int> min_diff;
    for (int i = 0; i <= N - K; i++) {
        int maxVal = *max_element(A.begin() + i + K, A.end());
        int minVal = *min_element(A.begin() + i, A.begin() + i + K);
        min_diff.push_back(maxVal - minVal);
    }
    
    cout << *min_element(min_diff.begin(), min_diff.end()) << endl;
    return 0;
}