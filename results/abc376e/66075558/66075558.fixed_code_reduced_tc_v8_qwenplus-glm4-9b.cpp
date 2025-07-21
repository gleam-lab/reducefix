#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        vector<pair<int, int>>AB(N); // Pair of (A[i], B[i])
        for (int i = 0; i < N; ++i) {
            AB[i] = {A[i], B[i]};
        }
        sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        long long min_value = LLONG_MAX;
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += AB[i].second;
            if (i >= K - 1) { // We have selected K elements
                min_value = min(min_value, AB[i].first * sum);
            }
        }

        cout << min_value << endl;
    }
    return 0;
}