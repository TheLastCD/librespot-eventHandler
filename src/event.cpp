#include <

#include "../headers/event.h"
#include "../headers/env.h"

#include <string>
#include <unordered_map>
#include <iostream>




PlaybackEvent stringToEvent(const std::string& sEvent) {

    // Trim whitespace from the input string
    std::string trimmedEvent = sEvent;
    trimmedEvent.erase(trimmedEvent.find_last_not_of(" \t\n\r\f\v") + 1);

    auto it = NonBlockingEventMap.find(trimmedEvent);
    return (it != NonBlockingEventMap.end()) ? it->second : PlaybackEvent::Unknown;
}


// Function to handle playback events
void handlePlaybackEvent(const std::string& sEvent) {
    PlaybackEvent event = stringToEvent(sEvent);
    std::cout << "Received event: " << sEvent << std::endl;
    SPlayPauseSeek sPlayPauseSeek;
    SSession sSession;
    switch (event) {
        case PlaybackEvent::ConDisConnected:
            sSession = {
                cEnvUsername ? cEnvUsername : "Unknown",
                cEnvConnectionID ? cEnvConnectionID : "Unknown"
            };
            break;
            
        case PlaybackEvent::PlayingPaused:
            sPlayPauseSeek = {
                cEnvTrackId ? cEnvTrackId : "Unknown",
                cEnvPosition ? cEnvShowPubTime :"0"
            };
            break;

        case PlaybackEvent::TrackChanging:

            break;
        case PlaybackEvent::VolumeChanged:

            break;
        case PlaybackEvent::Shuffle:

            break;

        
        case PlaybackEvent::Unknown:
            break;

        default:
            break;
    }
}