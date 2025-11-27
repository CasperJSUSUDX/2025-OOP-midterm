# Weather Analysis Toolkit - Skeleton Code

This directory contains the skeleton code for the OOP Mid-term Coursework.
Your task is to implement the missing functionality in the `.cpp` files.

## Files

- `main.cpp`: Entry point of the application.
- `WeatherSystem.h/cpp`: Main application logic (menu, data processing, plotting).
- `CSVReader.h/cpp`: Handles reading and parsing the CSV data file.
- `Candlestick.h/cpp`: Data structure for the aggregated weather data.

## Instructions

1.  **CSV Parsing**: Start by implementing `CSVReader::readCSV` in `CSVReader.cpp`. You need to parse the header to find the correct column for the country code and then read the data line by line.
2.  **Data Aggregation**: Implement `WeatherSystem::computeCandlesticks` in `WeatherSystem.cpp`. You need to group the raw data by the specified timeframe (Yearly, Monthly) and calculate the Open, High, Low, and Close values.
3.  **Plotting**: Implement `WeatherSystem::plotCandlesticks` to visualize the data using a text-based chart.
4.  **Prediction**: Implement a simple prediction model in `WeatherSystem::predictTemperature`.
5.  **Filtering**: Implement `WeatherSystem::filterData` to allow filtering by date range.

## Compilation

You can compile the project using g++:

```bash
g++ -std=c++11 main.cpp WeatherSystem.cpp CSVReader.cpp Candlestick.cpp -o weather_app
./weather_app
```
