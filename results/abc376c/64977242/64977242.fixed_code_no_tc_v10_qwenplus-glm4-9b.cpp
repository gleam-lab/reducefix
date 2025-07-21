#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Map the size of each toy to the smallest box that can contain it
    vector<long long> toy_to_box(N);
    for (int i = 0; i < N; i++) {
        toy_to_box[i] = A[i];
    }
    sort(toy_to_box.begin(), toy_to_box.end());
    
    for (int i = 0; i < N - 1; i++) {
        // Find the smallest box that can contain toy A[i]
        auto pos = lower_bound(toy_to_box.begin(), toy_to_box.end(), B[i]);
        if (pos == toy_to_box.end() || *pos < B[i]) {
            cout << -1 << endl;
            return 0;
        }
        toy_to_box.erase(pos); // Remove the box from consideration as it's now filled
    }

    cout << B[N - 1] << endl;
    return 0;
}