#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<WeatherReading> CSVReader::readCSV(const std::string& filename, const std::string& countryCode) {
    std::vector<WeatherReading> data;
    
    // TODO: 1. Open the file using std::ifstream
    
    // TODO: 2. Read the header line to find the index of the column for the specified countryCode
    // Hint: The column name format is likely "countryCode_temperature" (e.g., "AT_temperature")
    // Hint: Use std::getline and std::stringstream to parse the header
    
    // TODO: 3. Read the file line by line
    // Hint: Use a loop with std::getline
    // For each line:
    //   a. Parse the timestamp (usually the first column)
    //   b. Parse the temperature from the identified column index
    //   c. Create a WeatherReading object and add it to the data vector
    
    return data;
}
