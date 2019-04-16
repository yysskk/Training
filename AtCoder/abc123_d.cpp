// SeeAlso: https://atcoder.jp/contests/abc123/tasks/abc123_d
 
#include <bits/stdc++.h>
 
#define MAX 1000
 
typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
 
typedef long long ll;
 
using namespace std;
 
int main() {
    int X, Y, Z, K;
    ll A[MAX], B[MAX];
    priority_queue<ll, vector<ll>, less<ll>> C;

    cin >> X >> Y >> Z >> K;
 
    REP(i, X) {
        cin >> A[i];
    }
 
    REP(i, Y) {
        cin >> B[i];
    }
 
 
    REP(i, Z) {
        int c;
        cin >> c;
        C.push(c);
    }
  
    priority_queue<ll, vector<ll>, less<ll>> ab;
    priority_queue<ll, vector<ll>, less<ll>> ans2;

    REP(n, X) {
        REP(m, Y) {
            ab.push(A[n] + B[m]);
        }
    }
 
    int k = 0;
    while(k < K) {
        int maxAB = ab.top();
        int maxC = C.top();

        ab.pop();
        C.pop();

        cout << maxAB + maxC << endl;
        k++;
        cout << max((maxAB + C.top()), (ab.top() + maxC)) << endl;
        k++;
        cout << min((maxAB + C.top()), (ab.top() + maxC)) << endl;
        k++;
        cout << ab.top() + C.top() << endl;
        k++;
    }        
 
    return 0;
}
