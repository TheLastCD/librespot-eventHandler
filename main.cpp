#include <iostream>
#include <cstdlib> // For std::getenv
//#include <stdexcept> // For std::logic_error
#include <string>
#include "headers/meta.h"
#include "headers/env.h"
#include "headers/event.h"  

int main() {

    // Local variables
    const std::string Debug = "INFO";

    

    // Check if PLAYER_EVENT is null
    if (!cEnvPlayerEvent) {
        std::cerr << "Error: PLAYER_EVENT is not set." << std::endl;
        return 1; // Exit with error code
    }
    


    // Convert C-style strings to std::string safely
    // event
    std::string sEvent(cEnvPlayerEvent);

    // track specific 
    std::string sTrackId = cEnvTrackId ? cEnvTrackId : "Unknown Track ID";
    std::string sTrackName = cEnvTrackName ? cEnvTrackName : "Unknown Track Name";
    std::string sArtistName = cEnvArtistName ? cEnvArtistName : cEnvAlbumArtists ? cEnvAlbumArtists: "Unknown Artist"; // catch potential artist name not being present, experiment with ordering 
    std::string sAlbumName = cEnvAlbumName ? cEnvAlbumName : "Unknown Album";
    
    struct SSession{
        //possibly superfluous but adding just in case
        std::string m_UserName;
        std::string m_Connection_ID;
    };

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
        std::string m_ExplictFilter;
    };

    PlaybackEvent event = stringToEvent(sEvent);

    switch (event) {
        case PlaybackEvent::Start:
        case PlaybackEvent::TrackChanged:
            std::cout << "Playback started: " << sTrackName << " by " << sArtistName << std::endl;
            break;
        case PlaybackEvent::Stop:
            std::cout << "Playback stopped" << std::endl;
            break;
        case PlaybackEvent::Playing:
            std::cout << "Playing audio " << sTrackName << std::endl;
            break;
        case PlaybackEvent::Unknown:
        default:
            std::cout << "Unknown event: " << sEvent << std::endl;
            break;
    }


    return 0; // Exit successfully
}
