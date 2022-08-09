#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int count = 0, cnt = 0;
    double sum = 0;
    int t;
    while (cin >> t) {
        if (t < 0) count += 1;
        else if (t > 0) {
            sum += t;
            cnt++;
        }

    }
    if (cnt == 0) cout << count << endl << "0.0" << endl;
    else cout << count << endl << fixed << setprecision(1) << sum / (cnt * 1.0) << endl;


}