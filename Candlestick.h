#pragma once

#include <string>
#include <iostream>

class Candlestick {
public:
    std::string date;
    double open;
    double close;
    double high;
    double low;

    Candlestick(std::string d, double o, double c, double h, double l);
    void print() const;
};


