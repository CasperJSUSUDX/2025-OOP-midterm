#include "WeatherSystem.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>

void WeatherSystem::run(const std::string& filename) {
    // TODO: 1. Ask user for country code (e.g., "AT")
    std::string countryCode;
    std::cin >> countryCode;
    std::transform(countryCode.begin(), countryCode.end(), countryCode.begin(), [](unsigned char c) {return std::toupper(c);});
    
    // TODO: 2. Load data using CSVReader::readCSV
    std::vector<WeatherReading> data = CSVReader::readCSV(filename, countryCode);
    
    // TODO: 3. Implement a menu loop
    // Options should include:
    // 1. Plot Yearly Data
    // 2. Plot Monthly Data
    // 3. Filter Data
    // 4. Predict Temperature
    // 5. Exit

    // WeatherReading one{"1980-01-01T00:00:00Z", -3.64};
    // WeatherReading two{"1980-01-02T00:00:00Z",-6.666};
    // WeatherReading three{"1980-01-03T00:00:00Z",-6.343};
    // std::vector<WeatherReading> testData = {one, two, three};
    std::vector<Candlestick> candlesticks = computeCandlesticks(data, Timeframe::Yearly);
    // std::cout << "Date: " << candlesticks[0].date << "\nOpen: " << candlesticks[0].open << "\nClose: " << candlesticks[0].close << "\nHigh: " << candlesticks[0].high << "\nLow: " << candlesticks[0].low << "\n" << std::endl;
    for (const Candlestick& e: candlesticks)
    {
        std::cout << "Date: " << e.date << "\nOpen: " << e.open << "\nClose: " << e.close << "\nHigh: " << e.high << "\nLow: " << e.low << "\n" << std::endl;
    }
    
    // Based on the user's choice, call the appropriate helper functions
}

std::vector<Candlestick> WeatherSystem::computeCandlesticks(const std::vector<WeatherReading>& rawData, Timeframe timeframe) {
    std::vector<Candlestick> candlesticks;
    std::vector<double> temperatures;
    std::string currentTime = "";

    for (const WeatherReading& data: rawData)
    {
        std::string time;
        std::vector<std::string> dateKeys = CSVReader::split(CSVReader::split(data.timestamp, 'T')[0], '-');
        std::string year = dateKeys[0];
        std::string month = dateKeys[1];
        std::string day = dateKeys[2];
        switch (timeframe)
        {
            case Timeframe::Yearly:
                time = year;
                break;
            
            case Timeframe::Monthly:
                time = year + "-" + month;
                break;

            case Timeframe::Daily:
                time = year + "-" + month + "-" + day;
                break;
            
            default:
                time = year;
                break;
        }       

        if (currentTime == "")
        {
            currentTime = time;
        }
        if (time != currentTime)
        {
            // Compute and create Candlestick object then add it to the vector
            // std::cout << temperatures.size() << std::endl;
            std::max_element(temperatures.begin(), temperatures.end());
            double close;
            if (candlesticks.size() > 0)
            {
                close = candlesticks.back().close;
            }
            else
            {
                close = 0.0;
            }
            double min = *std::min_element(temperatures.begin(), temperatures.end());
            double max = *std::max_element(temperatures.begin(), temperatures.end());
            Candlestick candlestick{
                year + "-" + month + "-" + day,
                close,
                std::accumulate(temperatures.begin(), temperatures.end(), 0.0) / temperatures.size(),
                max,
                min
            };
            candlesticks.push_back(candlestick);
            currentTime = time;
            temperatures.clear();
        }
    
        temperatures.push_back(data.temp);

        if (&rawData.back() == &data)
        {
            // Compute and create Candlestick object then add it to the vector
            std::max_element(temperatures.begin(), temperatures.end());
            double close;
            if (candlesticks.size() > 0)
            {
                close = candlesticks.back().open;
            }
            else
            {
                close = 0.0;
            }
            double open = std::accumulate(temperatures.begin(), temperatures.end(), 0.0) / temperatures.size();
            double min = *std::min_element(temperatures.begin(), temperatures.end());
            double max = *std::max_element(temperatures.begin(), temperatures.end());
            Candlestick candlestick{
                year + "-" + month + "-" + day,
                close,
                open,
                max,
                min
            };
            candlesticks.push_back(candlestick);
        }
    }
    
    return candlesticks;
}

void WeatherSystem::plotCandlesticks(const std::vector<Candlestick>& candles, Timeframe timeframe) {
    // TODO: Implement a text-based plot
    
    // 1. Determine the range of temperatures (min and max) across all candles to scale the Y-axis
    
    // 2. Create a 2D buffer (e.g., std::vector<std::string>) to represent the plot area
    //    Height could be fixed (e.g., 20 lines), Width depends on number of candles
    
    // 3. Iterate through the candlesticks and draw them on the buffer
    //    - Scale the High, Low, Open, Close values to the Y-axis range
    //    - Use '|' for the wick (High to Low)
    //    - Use '#' or similar for the body (Open to Close)
    
    // 4. Print the buffer to the console
    //    - Print Y-axis labels (temperature values)
    //    - Print the plot lines
    //    - Print X-axis labels (dates)
}

void WeatherSystem::predictTemperature(const std::vector<Candlestick>& candles) {
    // TODO: Implement a simple prediction algorithm
    // Example: Calculate the average rate of change (slope) from the data
    // and apply it to the last known value to predict the next one.
}

std::vector<Candlestick> WeatherSystem::filterData(const std::vector<Candlestick>& candles, const std::string& startDate, const std::string& endDate) {
    std::vector<Candlestick> filtered;
    // TODO: Filter the candlesticks based on the date range
    // Keep only candles where date >= startDate and date <= endDate
    return filtered;
}
