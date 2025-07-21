#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        // Pair elements of A and B and sort by A in descending order
        vector<pair<int, int>> paired(N);
        for (int i = 0; i < N; i++) paired[i] = {A[i], B[i]};
        sort(paired.rbegin(), paired.rend());

        // Initialize variables for the solution calculation
        int min_value = LLONG_MAX;
        int cumulative_sum = 0;
        int count = 0;

        // Calculate the minimum possible value
        for (const auto& p : paired) {
            cumulative_sum += p.second;
            count++;
            if (count == K) {
                min_value = min(min_value, p.first * cumulative_sum);
                cumulative_sum -= p.second;
                count--;
            }
        }

        cout << min_value << endl;
    }

    return 0;
}