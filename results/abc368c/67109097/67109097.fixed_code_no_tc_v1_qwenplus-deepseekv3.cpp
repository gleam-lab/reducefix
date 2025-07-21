#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    long long low = 0, high = 1e18;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long total = 0;
        for (int i = 0; i < N; ++i) {
            long long damage = mid / 3 * 2 + mid % 3;
            if (H[i] > damage) {
                total += H[i] - damage;
            }
        }
        if (mid >= total) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}