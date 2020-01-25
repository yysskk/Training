#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


#define MAX 1000

typedef int _loop_int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<=(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) rep(i, h) { rep(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

int heap[MAX];
int H;

int parent(int i) { return heap[i/2]; }
int left(int i) { 
    if (H>=2*i) {
        return heap[2*i];
    } else {
        return -1;
    }
}

int right(int i) {
    if(H>=(2*i+1)) {
        return heap[2*i+1];
    } else {
        return -1;
    }
}
void maxHeapify(int i) {
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;
    if(heap[largest] < left(i)) {
        largest = l; 
    }
    if(heap[largest] < right(i)) {
        largest = r;
    }
    if(largest!=i) {
        swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
}

int main() {
    cin >> H;
    FOR(i, 1, H) {
        cin >> heap[i];
    }

    for(int i=H/2;i>=1;i--) {
        maxHeapify(i);
    }
    
    FOR(i, 1, H) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}
