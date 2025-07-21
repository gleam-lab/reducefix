#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(long long T, const vector<long long>& H) {
    long long count3 = T / 3;
    long long count1 = T - count3;
    for (long long h : H) {
        long long needed3 = min(h / 3, count3);
        h -= needed3 * 3;
        count3 -= needed3;
        count1 -= h;
        if (count1 < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long left = 0;
    long long right = 0;
    for (long long h : H) {
        right += h;
    }
    
    long long answer = right;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (isPossible(mid, H)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}