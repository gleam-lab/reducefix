#include <bits/stdc++.h>
using namespace std;

bool canStore(vector<int>& va, vector<int>& vb) {
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for(int i = 0; i < vb.size(); ++i) {
        if(va[i] > vb[i]) return false;
    }
    return true;
}

int minBoxSize(vector<int>& va, vector<int>& vb) {
    int left = *max_element(va.begin(), va.end()), right = *max_element(vb.begin(), vb.end()) + 1;
    while(left < right) {
        int mid = (left + right) / 2;
        vector<int> vb_copy = vb;
        vb_copy.push_back(mid);
        sort(vb_copy.begin(), vb_copy.end());
        if(canStore(va, vb_copy)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left == *max_element(vb.begin(), vb.end()) + 1 ? -1 : left;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 0; i < n-1; ++i) cin >> vb[i];
    cout << minBoxSize(va, vb) << endl;
    return 0;
}