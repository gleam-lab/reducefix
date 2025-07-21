#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index
        
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int pos = right;
        int l = pos, r = pos + 1;
        vector<long long> distances;
        while (distances.size() < N && (l >= 0 || r < N)) {
            if (l >= 0 && r < N) {
                if (abs(a[l] - b) <= abs(a[r] - b)) {
                    distances.push_back(abs(a[l] - b));
                    l--;
                } else {
                    distances.push_back(abs(a[r] - b));
                    r++;
                }
            } else if (l >= 0) {
                distances.push_back(abs(a[l] - b));
                l--;
            } else if (r < N) {
                distances.push_back(abs(a[r] - b));
                r++;
            }
        }
        
        cout << distances[k] << '\n';
    }
    
    return 0;
}