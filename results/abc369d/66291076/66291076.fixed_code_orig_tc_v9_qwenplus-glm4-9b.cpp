dp_odd[i] = max(dp_odd[i - 2] + 2 * a[i], dp_even[i - 1] + a[i]);
dp_even[i] = max(dp_even[i - 2] + a[i], dp_odd[i - 1] + 2 * a[i]);