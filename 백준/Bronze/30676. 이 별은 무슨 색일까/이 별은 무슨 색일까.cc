#include <iostream>

using namespace std;

int main() {
    int lambda;
    cin >> lambda;

    if (lambda >= 620 && lambda <= 780) {
        cout << "Red" << endl;
    } else if (lambda >= 590 && lambda < 620) {
        cout << "Orange" << endl;
    } else if (lambda >= 570 && lambda < 590) {
        cout << "Yellow" << endl;
    } else if (lambda >= 495 && lambda < 570) {
        cout << "Green" << endl;
    } else if (lambda >= 450 && lambda < 495) {
        cout << "Blue" << endl;
    } else if (lambda >= 425 && lambda < 450) {
        cout << "Indigo" << endl;
    } else if (lambda >= 380 && lambda < 425) {
        cout << "Violet" << endl;
    }

    return 0;
}
