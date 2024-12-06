

#include <string>
enum class PlaybackEvent {
    Start,
    TrackChanged,
    Stop,
    Playing,
    Paused,
    VolumeChanged,
    Connected,
    Disconnected,
    Loading,
    Unknown
};

PlaybackEvent stringToEvent(const std::string& sEvent);
void handlePlaybackEvent(const std::string& sEvent, const std::string& sTrackName, const std::string& sArtistName);
