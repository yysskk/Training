// SeeAlso: https://atcoder.jp/contests/abc123/tasks/abc123_a

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

#define MAX 100

int main() {
    int a, b, c, d, e, k;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> k;

    if ((e - a) <= k) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
