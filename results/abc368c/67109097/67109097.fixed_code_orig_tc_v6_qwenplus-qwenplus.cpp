#include <bits/stdc++.h>
using namespace std;

// Calculates the minimum T such that total damage >= h
long long get_required_T(long long h) {
    long long low = 0, high = 3 * h; // upper bound estimation
    while (low < high) {
        long long mid = (low + high) / 2;
        long long three_damage = mid / 3;
        long long one_damage = mid - three_damage;
        long long total_damage = three_damage * 3 + one_damage * 1;
        if (total_damage >= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i)
        cin >> H[i];

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long t_needed = get_required_T(H[i]);
        T += t_needed;
    }

    cout << T << endl;
    return 0;
}