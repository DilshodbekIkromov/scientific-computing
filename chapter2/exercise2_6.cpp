#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double f(long double x){ 
    return expl(x) + x*x*x - 5.0L; 
}
long double fprime(long double x){ 
    return expl(x) + 3.0L*x*x; 
}

int main() {    
    long double eps;
    cin >> eps;
    if (cin.fail() || eps <= 0.0L){
        return 0;
    }

    const int MAX_ITERS = 100;
    long double x_prev = 0.0L;

    for (int iter = 1; ; ++iter) {
        long double denom = fprime(x_prev);
        if (fabsl(denom) < 1e-18L) {          
            cout << iter-1 << '\n' << fixed << setprecision(10) << x_prev << '\n';
            return 0;
        }
        long double x_next = x_prev - f(x_prev) / denom;

        if (fabsl(x_next - x_prev) < eps || iter == MAX_ITERS) {
            cout << iter << '\n' << fixed << setprecision(10) << x_next << '\n';
            return 0;
        }
        x_prev = x_next;
    }
}
