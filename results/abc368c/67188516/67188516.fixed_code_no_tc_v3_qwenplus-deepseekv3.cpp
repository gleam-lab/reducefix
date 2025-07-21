#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(long long T, const vector<long long>& H) {
    long long additional = 0;
    for (long long h : H) {
        long long t = T;
        long long triple = t / 3;
        long long single = t - triple;
        if (single + 3 * triple >= h) {
            continue;
        } else {
            return false;
        }
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
    long long right = *max_element(H.begin(), H.end()) * 3; // Upper bound
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (isPossible(mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}