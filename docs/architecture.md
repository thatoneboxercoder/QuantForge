Validation Methodology
Purpose

This section documents how the C++ pricing engine (pricer.hpp/pricer.cpp) is verified for numerical correctness against the Python reference implementation. The goal is to catch genuine algorithmic bugs during the C++ port while allowing for expected floating-point rounding differences between the two languages.

Reference Values

The Python implementation (black_scholes.py) is treated as the source of truth, since it was developed and validated first. All validation is performed against a single test case (Set A):

S = 100, K = 100, r = 0.05, σ = 0.2, T = 1.0

For this input, the Python engine produces reference values for price, delta, gamma, vega, theta, and rho (for both call and put where applicable) — 10 quantities in total.

Tolerance

The C++ engine is required to match the Python reference to within a relative tolerance of 1×10⁻¹².

This value was chosen empirically. A direct comparison of the two engines on Set A showed absolute differences ranging from exactly 0 up to approximately 1.7×10⁻¹⁴ (on Vega, the largest-magnitude Greek in this test case), with corresponding relative differences no larger than roughly 1×10⁻¹⁵. A tolerance of 1×10⁻¹² sits comfortably above this observed noise floor — several orders of magnitude — while remaining tight enough to catch a real implementation bug, which would typically produce errors on the order of 10⁻³ or larger, not 10⁻¹⁴.

Source of Residual Differences

Both engines operate on IEEE 754 double-precision floats, so the small residual differences are not a precision mismatch between C++ and Python. The most likely sources are:

Differing operation order in floating-point arithmetic (e.g. how intermediate terms in d1/d2 are computed and combined), which can produce different rounding at the level of machine epsilon (~2.22×10⁻¹⁶).
Differing implementations of the normal CDF / error function — C++'s <cmath> (erf) versus Python's scipy.stats.norm or math.erf — which are not guaranteed to be bit-identical even for mathematically equivalent inputs.

These are expected and benign; they do not indicate a defect in either engine.

Enforcement

Correctness is enforced automatically in engine/cpp/tests/test_pricer.cpp via assert() checks, one per quantity. For each of the 10 values, the test computes:

relative_diff = |cpp_value - python_reference| / |python_reference|

and asserts relative_diff < 1e-12. A silent, zero-output run of the test binary indicates all 10 checks passed; a failed assertion halts execution and identifies which check failed via the crash message.

To run the validation suite:

g++ -o build\test_pricer.exe engine\cpp\tests\test_pricer.cpp engine\cpp\src\pricer.cpp -I engine\cpp\include

build\test_pricer.exe