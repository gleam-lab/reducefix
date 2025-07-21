#include<bits/stdc++.h>

using namespace std;

bool is_possible(long long T, const vector<int>& H) {
    long long cnt3 = T / 3;
    long long cnt1 = T - cnt3;
    for (int h : H) {
        long long needed3 = max(0LL, (h - cnt1 + 2) / 3);
        if (needed3 > cnt3) {
            return false;
        }
        cnt3 -= needed3;
        cnt1 -= (h - 3 * needed3);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long left = 0;
    long long right = 3 * 1e18;
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (is_possible(mid, H)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}