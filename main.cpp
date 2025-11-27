#include "WeatherSystem.h"
#include <iostream>

int main() {
    WeatherSystem app;
    // Default filename, can be overridden or passed as argument
    std::string filename = "weather_data_EU_1980-2019_temp_only.csv"; 
    
    // TODO: (Optional) Check if file exists or handle command line arguments
    
    app.run(filename);
    return 0;
}
