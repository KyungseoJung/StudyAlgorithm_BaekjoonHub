#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long A, B, V;
    cin >> A >> B >> V;

    long long days = (V - B + (A - B - 1)) / (A - B); 
    cout << days << endl;

    return 0;
}
