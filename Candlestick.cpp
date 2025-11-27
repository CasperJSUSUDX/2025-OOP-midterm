#include "Candlestick.h"
#include <iostream>
#include <iomanip>

Candlestick::Candlestick(std::string d, double o, double c, double h, double l)
    : date(d), open(o), close(c), high(h), low(l) {
    // Constructor implementation
}

void Candlestick::print() const {
    // TODO: Print the candlestick data in a readable format
    // Example output: 1980 Open: 10.5 Close: 12.0 High: 15.0 Low: 8.0
    // Hint: Use std::cout and std::setw for formatting if needed
}
