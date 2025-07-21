while (l < r) {
  num = (l + r) / 2;
  m = -1;
  for (int i = 0; i < N; i++) {
    if (a[i] <= num) {
      m = i;
    } else {
      break;
    }
  }
  if (m == N - 1) {
    if (a[0] <= b[N - 2]) {
      r = num;
    } else {
      l = num + 1;
    }
  } else {
    if (a[m + 1] <= b[m]) {
      l = num + 1;
    } else {
      r = num;
    }
  }
}