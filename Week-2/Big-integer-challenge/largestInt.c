// TASK =>finde the limits of the int type
#include <stdio.h>

int largestInt(int low, long high) {
  long mid = low + (high - low) / 2;
  int test = mid;
  if (test == mid) low = mid; 
  else high = mid; 
  if (high - low < 2) return test; 
  return largestInt(low, high);
};

int main() {
    int n = largestInt(0, 2500000000);
    printf("The largest int is %d\n", n);
    return 0;
};

