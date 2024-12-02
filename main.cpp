#include <iostream>
#include <cstdlib> // For std::getenv
//#include <stdexcept> // For std::logic_error
#include <string>
#include "src/headers/Track.h"
#include "src/headers/env.h"
#include "src/env.cpp"

int main() {

    // Local variables
    const std::string Debug = "INFO";





    

    // Check if PLAYER_EVENT is null
    if (!cEnvPlayerEvent) {
        std::cerr << "Error: PLAYER_EVENT is not set." << std::endl;
        return 1; // Exit with error code
    }
    
    // if (cEnvTrackName) {
    //     std::cout << "Header: " << cEnvTrackName << std::endl;
    // } else {
    //     std::cout << "TRACK_ID is not set." << std::endl;
    // }

    // Convert C-style strings to std::string safely
    // event
    std::string sEvent(cEnvPlayerEvent);

    // track specific 
    std::string sTrackId = cEnvTrackId ? cEnvTrackId : "Unknown Track ID";
    std::string sTrackName = cEnvTrackName ? cEnvTrackName : "Unknown Track Name";
    std::string sArtistName = cEnvArtistName ? cEnvArtistName : cEnvAlbumArtists ? cEnvAlbumArtists: "Unknown Artist"; // catch potential artist name not being present, experiment with ordering 
    std::string sAlbumName = cEnvAlbumName ? cEnvAlbumName : "Unknown Album";




    struct SClient {
        std::string m_ClientID;
        std::string m_ClientName;
        std::string m_ClientBrandName;
        std::string m_ClientModelName; 
    };

    struct SSpotifySettings {
        std::string m_Shuffle;
        std::string m_Repeat;
        std::string m_AutoPlay;
        std::string Filter;
    };

    // Handle events based on PLAYER_EVENT value
    if (sEvent == "start" || sEvent == "track_changed"){
        std::cout << "Playback started: " << sTrackName << " by " << sArtistName << std::endl;
    } else if (sEvent == "stop") {
        std::cout << "Playback stopped" << std::endl;
    } else if (sEvent == "playing"){
        std::cout << "Playing audio" << sTrackName << std::endl;

    }else {
        std::cout << "Unknown sEvent: " << sEvent << std::endl;
    }


    return 0; // Exit successfully
}