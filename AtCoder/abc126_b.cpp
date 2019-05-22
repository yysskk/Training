// SeeAlso: 

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

#define MAX 4
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main() {
    int S; 
    cin >> S;
  
    int a = S / 100;
    int b = S % 100;

    if(1 <= a && a <= 12){
        if(1 <= b && b <= 12) {
            cout << "AMBIGUOUS" <<endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if(1 <= b && b <= 12) {
            cout<< "YYMM" <<endl;
        } else {
            cout<< "NA" <<endl;
        }
    }
    
    return 0;
}
