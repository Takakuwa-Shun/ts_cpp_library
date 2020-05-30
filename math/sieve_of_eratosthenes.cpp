#include <iostream>

const long MAX_N = 100000000; // 10^8 8までが限界。
long cnt = 0, prime_num[MAX_N];
bool isPrime[MAX_N+1];

// n以下の素数の数を求める。蟻本p.112
int sieve(long n) {
  switch (n) {
  case 1:
    return 0;
  case 2:
    return 1;
  default:
    for (long i=0; i<=n; i+=2) {
      isPrime[i] = false;
    }
    for (long i=3; i<=n; i+=2) {
      isPrime[i] = true;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    prime_num[cnt++] = 2;
    for (long i=3; i<=n; i+=2) {
      if (isPrime[i]) {
        prime_num[cnt++] = i;
        for (long j = 2 * i; j<=n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    // for (long i=0; i<cnt; i++) {
    //   printf("%d ", prime_num[i]);
    // }
    return cnt;
  }
}

int main() {
  int n;
	scanf("%d", &n);
  printf("%d", sieve(n));
	return 0;
}