#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200010; // We use a larger size for simplicity
int a[MAX_N], cnt[MAX_N]; // cnt will store the cumulative number of points in the range

void update(int pos) {
    for (int i = pos; i < MAX_N; i += i & -i) {
        cnt[i]++;
    }
}

int query(int pos) {
    int sum = 0;
    for (int i = pos; i; i -= i & -i) {
        sum += cnt[i];
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        update(b[i]);
    }
    
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        // The distance for the k-th closest point
        // We need to find the smallest distance to the k-th closest point
        // Since k starts from 1, we need to find the (k-1)-th element in the sorted distances
        int low = -1e9, high = 1e9;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            // Calculate how many points A_i are within distance mid from B_j
            int count = query(max(1, x - mid)) - query(max(1, x + 1 - mid));
            if (count >= k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        // low should now be the answer
        cout << low << endl;
    }
    
    return 0;
}