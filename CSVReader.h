#pragma once

#include <string>
#include <vector>

struct WeatherReading {
    std::string timestamp;
    double temp;
};

class CSVReader {
public:
    /**
     * Reads weather data from a CSV file.
     * @param filename The path to the CSV file.
     * @param countryCode The country code to filter/select columns (e.g., "AT").
     * @return A vector of WeatherReading objects.
     */
    static std::vector<WeatherReading> readCSV(const std::string& filename, const std::string& countryCode);
    
private:
    static std::vector<std::string> split(const std::string& string, const char& delimiter);
};


