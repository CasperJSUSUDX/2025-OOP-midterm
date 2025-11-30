#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<WeatherReading> CSVReader::readCSV(const std::string& filename, const std::string& countryCode) {
    std::vector<WeatherReading> data;
    
    // TODO: 1. Open the file using std::ifstream
    std::ifstream csvFile{filename};
    
    if (csvFile.is_open())
    {
        // TODO: 2. Read the header line to find the index of the column for the specified countryCode
        // Hint: The column name format is likely "countryCode_temperature" (e.g., "AT_temperature")
        // Hint: Use std::getline and std::stringstream to parse the header
        std::string line;
        unsigned int index;
        std::getline(csvFile, line);
        std::vector<std::string> tokens = split(line, ',');
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i].find(countryCode))
            {
                index = i;
                break;
            }
        }

        // TODO: 3. Read the file line by line
        // Hint: Use a loop with std::getline
        // For each line:
        //   a. Parse the timestamp (usually the first column)
        //   b. Parse the temperature from the identified column index
        //   c. Create a WeatherReading object and add it to the data vector
        while (std::getline(csvFile, line))
        {
            tokens = split(line, ',');
            std::cout << "Time: " << tokens[0] << "\nTemperature: " << tokens[index] << std::endl;
            WeatherReading weather{
                tokens[0],
                std::stod(tokens[index])
            };
            data.push_back(weather);
        }

        csvFile.close();
    }
    
    return data;
}

std::vector<std::string> CSVReader::split(const std::string& string, const char& delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(string);
    
    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    
    return tokens;
}
