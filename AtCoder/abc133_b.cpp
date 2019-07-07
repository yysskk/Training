// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 10

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int N, D;
int X[MAX][MAX];

bool isSquare(int n) {
    int temp = sqrt(n);
    return (n == pow(temp, 2));
}

int main() {
    
    cin >> N >> D;

    REP(i, N) {
        REP(j, D) {
            cin >> X[i][j];
        }
    }

    int ans = 0;

    REP(i, (N-1)) {
        for(int j = i+1; j < N; j++) {
            int sum = 0;
            REP(t, D) {
                sum += pow((X[i][t] - X[j][t]), 2);
            }

            bool temp = isSquare(sum);

            if (temp) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

