#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2 * 100005;
int A[MAXN], B[MAXN];

bool canFit(int x, int N, int A[], int B[]) {
    sort(A + 1, A + N + 1);
    sort(B + 1, B + N);

    int j = 0;
    for (int i = 1; i <= N; ++i) {
        while (j < N - 1 && B[j] < A[i]) {
            ++j;
        }
        if (j == N - 1 || B[j] < A[i]) {
            return false;
        }
        ++j;
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

    int left = 1, right = 1e9, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFit(mid, N, A, B)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}