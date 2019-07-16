// SeeAlso: https://atcoder.jp/contests/abc122/tasks/abc122_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int dp[101][4][4][4]; 
 
int main(){
 
    int N;
    cin >> N;
 
    dp[0][3][3][3] = 1;
 
    int mod = 1e9 + 7;
 
    for(int len = 0; len < N; len++){
        for(int c1 = 0; c1 < 4; c1++){
            for(int c2 = 0; c2 < 4; c2++){

                for(int c3 = 0; c3 < 4; c3++){
 
                    if(dp[len][c1][c2][c3] == 0) continue;
 
                    for(int a = 0; a < 4; a++){
 
                        if(a == 2 && c1 == 1 && c2 == 0) continue;
                        if(a == 2 && c1 == 0 && c2 == 1) continue;
                        if(a == 1 && c1 == 2 && c2 == 0) continue;
                        if(a == 2 && c1 == 1 && c3 == 0) continue;
                        if(a == 2 && c2 == 1 && c3 == 0) continue;
 
                        dp[len+1][a][c1][c2] += dp[len][c1][c2][c3];
                        dp[len+1][a][c1][c2] %= mod;
                    }
                }
            }
        }
    }
 
    int ans = 0;
    
    for(int c1 = 0; c1 < 4; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            for(int c3 = 0; c3 < 4; c3++){
                ans += dp[N][c1][c2][c3];
                ans %= mod;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
