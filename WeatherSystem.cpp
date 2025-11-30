#include "WeatherSystem.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

void WeatherSystem::run(const std::string& filename) {
    // TODO: 1. Ask user for country code (e.g., "AT")
    std::string countryCode;
    std::cin >> countryCode;
    
    // TODO: 2. Load data using CSVReader::readCSV
    CSVReader::readCSV(filename, countryCode);
    
    // TODO: 3. Implement a menu loop
    // Options should include:
    // 1. Plot Yearly Data
    // 2. Plot Monthly Data
    // 3. Filter Data
    // 4. Predict Temperature
    // 5. Exit
    
    // Based on the user's choice, call the appropriate helper functions
}

std::vector<Candlestick> WeatherSystem::computeCandlesticks(const std::vector<WeatherReading>& rawData, Timeframe timeframe) {
    std::vector<Candlestick> candlesticks;
    
    // TODO: 1. Group data based on the timeframe (Year, Month, or Day)
    // Hint: You can use a std::map<std::string, std::vector<double>> to group temperatures by date key
    // - For Yearly: key = YYYY
    // - For Monthly: key = YYYY-MM
    std::map<std::string, double> dataPair;
    for (const WeatherReading& data: rawData)
    {
        dataPair.insert({data.timestamp, data.temp});
    }
    
    // TODO: 2. For each group, compute the candlestick data:
    // - High: Max temperature in the group
    // - Low: Min temperature in the group
    // - Close: Average temperature of the group
    // - Open: The 'Close' of the previous timeframe (or the first 'Close' for the very first item)
    
    // TODO: 3. Create Candlestick objects and add them to the vector
    
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
