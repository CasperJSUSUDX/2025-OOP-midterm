#pragma once

#include "Candlestick.h"
#include "CSVReader.h"
#include <vector>
#include <string>

enum class Timeframe {
    Yearly,
    Monthly,
    Daily
};

class WeatherSystem {
public:
    void run(const std::string& filename);

private:
    std::vector<Candlestick> computeCandlesticks(const std::vector<WeatherReading>& rawData, Timeframe timeframe);
    void plotCandlesticks(const std::vector<Candlestick>& candles, Timeframe timeframe);
    void predictTemperature(const std::vector<Candlestick>& candles);
    std::vector<Candlestick> filterData(const std::vector<Candlestick>& candles, const std::string& startDate, const std::string& endDate);
    void printMenu();
};


