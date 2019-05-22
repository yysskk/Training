// SeeAlso: https://atcoder.jp/contests/abc126/tasks/abc126_c

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

#define MAX 4
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int N, K;

double win = 0;
double sum = 0;

int main() {
    cin >> N >> K;
    double ans = 0;

    for(int i = 1; i < (N+1); i++) {
        double prob = 1.0/N;
        int value = i;
        while(value<K){
            value *= 2;
            prob *= 0.5;
        }
        ans += prob;
    }

    cout << setprecision(10) << ans << endl;

    return 0;
}
