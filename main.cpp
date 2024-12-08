#include <iostream>
#include <cstdlib> // For std::getenv
#include <string>

#include "lib/json/single_include/nlohmann/json.hpp"

#include "headers/env.h"
#include "headers/event.h"  

int main() {
    

    // Check if PLAYER_EVENT is null
    if (!cEnvPlayerEvent) {
        std::cerr << "Error: PLAYER_EVENT is not set." << std::endl;
        return 1; // Exit with error code
    }
    
    // Event to be Processed
    std::string sEvent(cEnvPlayerEvent);

    // track specific 
    std::string sTrackId = cEnvTrackId ? cEnvTrackId : "Unknown Track ID";
    std::string sTrackName = cEnvTrackName ? cEnvTrackName : "Unknown Track Name";
    std::string sArtistName = cEnvArtistName ? cEnvArtistName : cEnvAlbumArtists ? cEnvAlbumArtists: "Unknown Artist"; // catch potential artist name not being present, experiment with ordering 
    std::string sAlbumName = cEnvAlbumName ? cEnvAlbumName : "Unknown Album";
    

    std::string SinkStatus;

    nlohmann::json payload = handlePlaybackEvent(sEvent);
    std::cout << payload.dump() << std::endl;

    return 0; // Exit successfully
}
