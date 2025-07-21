#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define int long long

int n, q;
vector<int> a;

int find_kth_distance(int b, int k) {
    int low = 0, high = 2e14;
    int answer = high;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int left_pos = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
        int right_pos = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
        int count = right_pos - left_pos;
        
        if (count >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        int low = 0, high = 2e14;
        int answer = high;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int left_pos = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int right_pos = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            int count = right_pos - left_pos;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        vector<int> distances;
        int left_pos = lower_bound(a.begin(), a.end(), b - answer) - a.begin();
        int right_pos = upper_bound(a.begin(), a.end(), b + answer) - a.begin();
        for (int i = left_pos; i < right_pos; ++i) {
            distances.push_back(abs(a[i] - b));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}