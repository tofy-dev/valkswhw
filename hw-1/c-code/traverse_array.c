#include <stdio.h>
#include <stddef.h>

int main () {

  int n;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  int l, r;
  scanf("%d %d", &l, &r);

  for (size_t i = r; i >= l; --i) {
    if (i == -1 || i >= n) break;
    printf("%d ", arr[i]);
  }

  return 0;
}
