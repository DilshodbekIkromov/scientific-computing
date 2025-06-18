#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double f(long double x){ 
    return expl(x) + x * x * x - 5.0L; 
}
long double fprime(long double x){ 
    return expl(x) + 3.0L * x * x; 
}

int main() {
    long double eps;
    cout << "Enter desired precision (eps): ";
    cin >> eps;
    if (cin.fail() || eps <= 0.0L || eps >= 1.0L) {
        cout << "Invalid input. Exiting.\n";
        return 0;
    }

    const int MAX_ITERS = 100;
    long double x_prev = 0.0L;

    for (int iter = 1; ; ++iter) {
        long double denom = fprime(x_prev);
        if (fabsl(denom) < 1e-18L) {
            cout << "Stopped: derivative too small after " << iter - 1 << " iterations.\n";
            cout << "Last approximation: " << fixed << setprecision(10) << x_prev << '\n';
            return 0;
        }
        long double x_next = x_prev - f(x_prev) / denom;
        if (fabsl(x_next - x_prev) < eps || iter == MAX_ITERS) {
            cout << "Converged after " << iter << " iterations.\n";
            cout << "Root approximation: " << fixed << setprecision(10) << x_next << '\n';
            return 0;
        }
        x_prev = x_next;
    }
}
