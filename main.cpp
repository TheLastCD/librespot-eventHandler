#include <iostream>
#include <cstdlib> // For std::getenv
#include <string>

#include "lib/curlpp/include/curlpp/cURLpp.hpp" 
  
#include "lib/json/single_include/nlohmann/json.hpp"

#include "headers/env.h"
#include "headers/event.h"  

int main(int argc, char *argv[]) {

    
    // Access the command-line arguments
    const char *port = argv[1]; // First argument
    const char *destination = argv[2]; // Second argument

    // Check if PLAYER_EVENT is null
    if (!cEnvPlayerEvent) {
        std::cerr << "Error: PLAYER_EVENT is not set." << std::endl;
        return 1; // Exit with error code
    }
    
    // Event to be Processed
    std::string sEvent(cEnvPlayerEvent);



    nlohmann::json payload = handlePlaybackEvent(sEvent);
    std::cout << payload.dump() << std::endl;

    return 0; // Exit successfully
}
