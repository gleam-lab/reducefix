#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int arr[N], tree[N + 1];

// Update the tree with a new value at position i
void update(int i, int val) {
    while (i <= N) {
        tree[i] += val;
        i += i & -i;
    }
}

// Query the sum of values from position 1 to pos
int query(int pos) {
    int s = 0;
    while (pos) {
        s += tree[pos];
        pos -= pos & -pos;
    }
    return s;
}

// Binary search to find the k-th smallest distance
int binary_search(int val, int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (query(tree[mid]) < val)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_dist = -1e9 - 1;
    for (int i = 0; i < q; i++) {
        int b, k;
        scanf("%d %d", &b, &k);
        max_dist = max(max_dist, b);
        update(arr[i], b);
    }

    for (int i = 0; i < q; i++) {
        int b, k;
        scanf("%d %d", &b, &k);
        int index = binary_search(k, 0, N);
        int min_dist = max_dist + 1;
        if (index <= N)
            min_dist = min(min_dist, abs(b - arr[index - 1]));
        if (index > 0)
            min_dist = min(min_dist, abs(b - arr[index]));
        printf("%d\n", min_dist);
    }

    return 0;
}