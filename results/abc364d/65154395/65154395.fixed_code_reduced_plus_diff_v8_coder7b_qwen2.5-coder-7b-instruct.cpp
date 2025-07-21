#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int q = 0; q < Q; ++q) {
        int B, k;
        cin >> B >> k;

        // Map to store distances from B to all points A
        map<int, int> dist_count;
        
        for (int a : A) {
            int d = abs(a - B);
            dist_count[d]++;
        }

        int count = 0;
        for (auto& [dist, freq] : dist_count) {
            count += freq;
            if (count >= k) {
                cout << dist << endl;
                break;
            }
        }
    }

    return 0;
}