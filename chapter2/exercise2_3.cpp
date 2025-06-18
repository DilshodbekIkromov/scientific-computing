#include <iostream>
using namespace std;

int main(){
    int number = 0;

    cout << "Enter number, so I will add them, press -1 if you want to stop" << endl;
    cin >> number;
    int sum = 0;
    while (number != -1) {
        sum += number;
        if (sum > 100) {
            cout << "Sum exceeded 100. Terminating." << endl;
            break;
        }
        cout << "Enter number again: " << endl;
        cin >> number;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}