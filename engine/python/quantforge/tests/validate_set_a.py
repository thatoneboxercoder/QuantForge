import numpy as np
from quantforge.pricing.black_scholes import black_scholes_price, black_scholes_delta, black_scholes_gamma, black_scholes_rho, black_scholes_theta, black_scholes_vega

print(black_scholes_price(100, 100, 0.05, 0.2, 1.0, "call"))
print(black_scholes_price(100, 100, 0.05, 0.2, 1.0, "put"))
print(black_scholes_delta(100, 100, 0.05, 0.2, 1.0, "call"))

print(black_scholes_delta(100, 100, 0.05, 0.2, 1.0, "put"))
print(black_scholes_gamma(100, 100, 0.05, 0.2, 1.0))
print(black_scholes_vega(100, 100, 0.05, 0.2, 1.0))
print(black_scholes_theta(100, 100, 0.05, 0.2, 1.0, "call"))
print(black_scholes_theta(100, 100, 0.05, 0.2, 1.0, "put"))
print(black_scholes_rho(100, 100, 0.05, 0.2, 1.0, "call"))
print(black_scholes_rho(100, 100, 0.05, 0.2, 1.0, "put"))