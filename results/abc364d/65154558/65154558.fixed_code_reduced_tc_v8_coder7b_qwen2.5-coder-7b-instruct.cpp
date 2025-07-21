#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 100005;
int A[MAXN], B[MAXQ], K[MAXQ];
long long D[MAXN];

void merge_sort(long long arr[], int left, int right) {
    if (left == right) return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            D[k++] = arr[i++];
        } else {
            D[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        D[k++] = arr[i++];
    }
    while (j <= right) {
        D[k++] = arr[j++];
    }
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = D[k];
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> K[i];
    }

    for (int i = 0; i < Q; ++i) {
        int idx = lower_bound(A, A + N, B[i]) - A;
        long long dist = abs(B[i] - A[idx]);
        if (idx > 0) dist = min(dist, abs(B[i] - A[idx - 1]));
        if (idx < N - 1) dist = min(dist, abs(B[i] - A[idx + 1]));

        if (K[i] == 1) {
            cout << dist << '\n';
        } else {
            long long cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (abs(A[j] - B[i]) <= dist) ++cnt;
            }
            cout << dist * (K[i] - cnt) << '\n';
        }
    }

    return 0;
}