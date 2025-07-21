while(hi-lo>1)
   ```
   can leave `hi` as a potentially valid solution which isn't checked properly afterward.

We'll fix this by:
- Setting a more reasonable upper bound for binary search.
- Ensuring both `lo` and `hi` are checked at the end.
- Making sure the binary search narrows down correctly.

Here’s the complete corrected version of your code: