#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2 * 100005;

vector<int> A(MAXN), B(MAXN);

bool canFit(int x) {
    vector<int> boxes(B.begin(), B.end());
    sort(boxes.begin(), boxes.end());
    
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > x) return false;
        
        auto it = upper_bound(boxes.begin(), boxes.end(), A[i]);
        if (it != boxes.begin()) {
            --it;
            boxes.erase(it);
        } else {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 1; i < N; ++i) {
        cin >> B[i];
    }
    
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canFit(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << (canFit(left) ? left : -1) << endl;
    
    return 0;
}