int N;
cin >> N;
vector<int> A(N);
vector<int> B(N - 1);

// Input the sizes of the toys and boxes
for (int i = 0; i < N; ++i) {
    cin >> A[i];
}
for (int i = 0; i < N - 1; ++i) {
    cin >> B[i];
}

// Find the maximum toy size
int max_size = *max_element(A.begin(), A.end());

// Find the minimum box size that is not less than max_size
int min_box_size = INT_MAX;
for (int size : B) {
    if (size >= max_size && size < min_box_size) {
        min_box_size = size;
    }
}

// If we found a valid box size, print it; otherwise, print -1
if (min_box_size != INT_MAX) {
    cout << min_box_size << endl;
} else {
    cout << -1 << endl;
}