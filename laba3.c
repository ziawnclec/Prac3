#include <stdio.h>

long long count_numbers(int p) {
    if (p == 0) return 0;
    if (p == 1) return 2;
    if (p == 2) return 4;

    long long dp[p+1][2];
    dp[1][0] = 2;
    dp[1][1] = 0;
    dp[2][0] = 2;
    dp[2][1] = 2;

    for (int i = 3; i <= p; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    return dp[p][0] + dp[p][1];
}

int main() {
    int p;
    printf("Vvedit kilkist rozryadiv: ");
    scanf("%d", &p);

    long long result = count_numbers(p);
    printf("Kilkist chisel z %d rozryadiv: %lld\n", p, result);

    return 0;
}
