#include "../headers/event.h"
#include <string>
#include <iostream>


// Helper function to convert string to enum
PlaybackEvent stringToEvent(const std::string& sEvent) {
    if (sEvent == "start" || sEvent == "track_changed") return PlaybackEvent::Start;
    if (sEvent == "stop") return PlaybackEvent::Stop;
    if (sEvent == "playing") return PlaybackEvent::Playing;
    if (sEvent == "paused") return PlaybackEvent::Paused;
    if (sEvent == "volume_changed") return PlaybackEvent::VolumeChanged;
    if (sEvent == "session_connected") return PlaybackEvent::Connected;
    if (sEvent == "session_disconnected") return PlaybackEvent::Disconnected;
    if (sEvent == "loading") return PlaybackEvent::Loading;
    return PlaybackEvent::Unknown;
}


// Function to handle playback events
void handlePlaybackEvent(const std::string& sEvent, const std::string& sTrackName, const std::string& sArtistName) {
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
}