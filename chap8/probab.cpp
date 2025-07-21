#include <cstddef>
#include <cassert>
#include <iostream>

template<std::size_t N>
class ProbabilityArray {
    static_assert(N > 0, "ProbabilityArray size must be > 0");
    static constexpr double eps = 1e-6;

    double data[N];

public:
    constexpr std::size_t size() const noexcept { return N; }

    double& operator[](std::size_t i) {
        assert(i < N && "Index out of bounds");
        return data[i];
    }

    double operator[](std::size_t i) const {
        assert(i < N && "Index out of bounds");
        double x = data[i];

        if (x >= 0.0 && x <= 1.0) {
            return x;
        }
        if (x >= -eps && x < 0.0) {
            return 0.0;
        }
        if (x > 1.0 && x <= 1.0 + eps) {
            return 1.0;
        }

        assert(false && "Probability out of allowed range [-eps, 1+eps]");
        return x;
    }
};

int main() {
    ProbabilityArray<5> pa;

    // Assign values
    pa[0] = 0.5;
    pa[1] = -5e-7;
    pa[2] = 1.0 + 8e-7;
    pa[3] = 0.8;
    pa[4] = 2.0;

    // Create a const reference to force const operator[]
    const auto& const_pa = pa;

    // Now this will use the const version with clamping
    for (std::size_t i = 0; i < const_pa.size(); ++i) {
        std::cout << "pa[" << i << "] = " << const_pa[i] << "\n";
    }

    return 0;
}