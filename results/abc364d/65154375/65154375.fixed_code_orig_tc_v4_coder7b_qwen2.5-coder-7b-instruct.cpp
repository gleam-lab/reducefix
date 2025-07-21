#include<bits/stdc++.h>
using namespace std;

vector<int> a;

bool compare(int x, int y){
    return a[x] < a[y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> queries(q);
    for(int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k - 1};
    }

    sort(a.begin(), a.end());

    for(auto query : queries) {
        int b = query[0], k = query[1];
        auto it = upper_bound(a.begin(), a.end(), b);
        int index = it - a.begin();

        if(index == 0) cout << abs(b - a[index]) << endl;
        else if(index == n) cout << abs(b - a[index - 1]) << endl;
        else {
            int left = abs(b - a[index - 1]), right = abs(b - a[index]);
            if(left <= right) cout << left << endl;
            else cout << right << endl;
        }
    }

    return 0;
}