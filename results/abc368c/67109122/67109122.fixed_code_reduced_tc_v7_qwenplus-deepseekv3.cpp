#include<bits/stdc++.h>

using namespace std;

long long compute_min_T(long long H) {
    long long low = 0, high = 2 * H;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long damage = mid + 2 * (mid / 3);
        if (damage >= H) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long total_T = 0;
    for (int i = 0; i < N; i++) {
        long long T_i = compute_min_T(H[i]);
        if (i < N - 1) {
            H[i + 1] = max(0LL, H[i + 1] - (T_i / 3));
        }
        total_T += T_i;
    }

    cout << total_T << endl;
    return 0;
}