#include "pricer.hpp"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setprecision(15);

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