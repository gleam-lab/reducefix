#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e8 + 5;

int N, Q;
vector<int> A[MAXN];
int B[100001], K[100001];

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        A[a].push_back(i);
    }
    for (int i = 1; i <= Q; ++i) {
        cin >> B[i] >> K[i];
    }
    
    for (int j = 1; j <= Q; ++j) {
        sort(A[B[j]].begin(), A[B[j]].end());
        int k = K[j];
        if (A[B[j]].size() < k) {
            cout << 0 << endl;
        } else {
            int x = A[B[j]][k - 1];
            long long dist = (long long)B[j] - x;
            cout << dist * dist << endl;
        }
    }
    
    return 0;
}