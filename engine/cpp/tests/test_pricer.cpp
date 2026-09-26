#include "pricer.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

int main() {

    const double RELATIVE_TOL = 1e-12;

    const double PYTHON_CALL_PRICE = 10.450583572185565;
    double cpp_call_price = black_scholes_price(100, 100, 0.05, 0.2, 1.0, "call"); 
    double call_price_diff = fabs(cpp_call_price - PYTHON_CALL_PRICE) / fabs(PYTHON_CALL_PRICE);
    bool call_price_passed = call_price_diff < RELATIVE_TOL;

    assert(call_price_passed);

    const double PYTHON_PUT_PRICE = 5.573526022256971;
    double cpp_put_price = black_scholes_price(100, 100, 0.05, 0.2, 1.0, "put");
    double put_price_diff = fabs(cpp_put_price - PYTHON_PUT_PRICE) / fabs(PYTHON_PUT_PRICE);
    bool put_price_passed = put_price_diff < RELATIVE_TOL;

    assert(put_price_passed);

    const double PYTHON_CALL_DELTA = 0.6368306511756191;
    double cpp_call_delta = black_scholes_delta(100, 100, 0.05, 0.2, 1.0, "call");
    double call_delta_diff = fabs(cpp_call_delta - PYTHON_CALL_DELTA) / fabs(PYTHON_CALL_DELTA);
    bool call_delta_passed = call_delta_diff < RELATIVE_TOL;

    assert(call_delta_passed);

    const double PYTHON_PUT_DELTA = -0.3631693488243809;
    double cpp_put_delta = black_scholes_delta(100, 100, 0.05, 0.2, 1.0, "put");
    double put_delta_diff = fabs(cpp_put_delta - PYTHON_PUT_DELTA) / fabs(PYTHON_PUT_DELTA);
    bool put_delta_passed = put_delta_diff < RELATIVE_TOL;

    assert(put_delta_passed);

    const double PYTHON_GAMMA = 0.018762017345846895;
    double cpp_gamma =  black_scholes_gamma(100, 100, 0.05, 0.2, 1.0);
    double gamma_diff = fabs(cpp_gamma - PYTHON_GAMMA) / fabs(PYTHON_GAMMA);
    bool gamma_passed = gamma_diff < RELATIVE_TOL;

    assert(gamma_passed);

    const double PYTHON_VEGA = 37.52403469169379;
    double cpp_vega = black_scholes_vega(100, 100, 0.05, 0.2, 1.0);
    double vega_diff = fabs(cpp_vega - PYTHON_VEGA) / fabs(PYTHON_VEGA);
    bool vega_passed = vega_diff < RELATIVE_TOL;

    assert(vega_passed);

    const double PYTHON_CALL_THETA = -6.414027546438197;
    double cpp_call_theta = black_scholes_theta(100, 100, 0.05, 0.2, 1.0, "call");
    double call_theta_diff = fabs(cpp_call_theta - PYTHON_CALL_THETA) / fabs(PYTHON_CALL_THETA);
    bool call_theta_passed = call_theta_diff < RELATIVE_TOL;

    assert(call_theta_passed);

    const double PYTHON_PUT_THETA = -1.657880423934626;
    double cpp_put_theta = black_scholes_theta(100, 100, 0.05, 0.2, 1.0, "put");
    double put_theta_diff = fabs(cpp_put_theta - PYTHON_PUT_THETA) / fabs(PYTHON_PUT_THETA);
    bool put_theta_passed = put_theta_diff < RELATIVE_TOL;

    assert(put_theta_passed);

    const double PYTHON_CALL_RHO = 53.232481545376345;
    double cpp_call_rho = black_scholes_rho(100, 100, 0.05, 0.2, 1.0, "call");
    double call_rho_diff = fabs(cpp_call_rho - PYTHON_CALL_RHO) / fabs(PYTHON_CALL_RHO);
    bool call_rho_passed = call_rho_diff < RELATIVE_TOL;

    assert(call_rho_passed);

    const double PYTHON_PUT_RHO = -41.89046090469506;
    double cpp_put_rho = black_scholes_rho(100, 100, 0.05, 0.2, 1.0, "put");
    double put_rho_diff = fabs(cpp_put_rho - PYTHON_PUT_RHO) / fabs(PYTHON_PUT_RHO);
    bool put_rho_passed = put_rho_diff < RELATIVE_TOL;

    assert(put_rho_passed);

    std::cout << std::setprecision(17);

    double S = 100, K = 100, r = 0.05, sigma = 0.2, T = 1.0;

    std::cout << "Call Price: " << black_scholes_price(S, K, r, sigma, T, "call") << std::endl;
    std::cout << "Put Price: " << black_scholes_price(S, K, r, sigma, T, "put") << std::endl;

    std::cout << "Call Delta: " << black_scholes_delta(S, K, r, sigma, T, "call") << std::endl;
    std::cout << "Put Delta: " << black_scholes_delta(S, K, r, sigma, T, "put") << std::endl;

    std::cout << "Gamma: " << black_scholes_gamma(S, K, r, sigma, T) << std::endl;
    std::cout << "Vega: " << black_scholes_vega(S, K, r, sigma, T) << std::endl;

    std::cout << "Call Theta: " << black_scholes_theta(S, K, r, sigma, T, "call") << std::endl;
    std::cout << "Put Theta: " << black_scholes_theta(S, K, r, sigma, T, "put") << std::endl;

    std::cout << "Call Rho: " << black_scholes_rho(S, K, r, sigma, T, "call") << std::endl;
    std::cout << "Put Rho: " << black_scholes_rho(S, K, r, sigma, T, "put") << std::endl;

    return 0;

}