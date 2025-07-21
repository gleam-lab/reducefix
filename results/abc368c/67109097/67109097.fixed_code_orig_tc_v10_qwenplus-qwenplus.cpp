#include <bits/stdc++.h>

using namespace std;

bool can_defeat_all(int N, vector<long long>& H, long long T) {
    // We'll keep track of how many triple attacks we can make
    long long triple_attacks = T / 3;
    long long single_attacks = T - triple_attacks;

    for (int i = 0; i < N; ++i) {
        long long h = H[i];

        // Prioritize triple attacks
        long long needed_triples = min(triple_attacks, h / 3 + (h % 3 != 0 ? 1 : 0));
        h -= needed_triples * 3;
        triple_attacks -= needed_triples;

        if (h <= 0) continue;

        // Use single attacks if triples are not enough
        if (single_attacks >= h) {
            single_attacks -= h;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long low = 0;
    long long high = 1e18; // Upper bound for binary search

    while (low < high) {
        long long mid = (low + high) / 2;
        if (can_defeat_all(N, H, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;

    return 0;
}