#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <cstring>

int main() {
  int n;  
  scanf("%d", &n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    char op[2];
    int inp = 0;
    scanf(" %s %d",op,&inp);

    if (strcmp(op,"+") == 0)
      ans += inp;
    else if (strcmp(op,"-") == 0)
      ans -= inp;
    else if (strcmp(op,"*") == 0)
      ans *= inp;
    else if (strcmp(op,"/") == 0)
      ans /= inp;
    else
      ans = pow(ans,inp);
  }

  printf("%d",ans);
}

