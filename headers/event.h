
#include <unordered_map>
#include <string>


enum class PlaybackEvent {
    ConDisConnected,
    PlayingPaused,
    SessionClientChanged,
    TrackChanging,
    VolumeChanged,
    Shuffle,
    Repeat,
    Filter,
    AutoPlay,
    TrackChanged,
    Blocking,
    Unknown
};


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

struct SPlayPauseSeek {
    std::string m_TrackID;
    std::string m_PositionMS;
};



static const std::unordered_map<std::string, PlaybackEvent> NonBlockingEventMap  = {
    {"session_connected", PlaybackEvent::ConDisConnected},
    {"session_disconnected", PlaybackEvent::ConDisConnected},
    {"session_client_changed", PlaybackEvent::SessionClientChanged},
    {"volume_changed", PlaybackEvent::VolumeChanged},
    {"shuffle_changed", PlaybackEvent::Shuffle},
    {"repeat_changed", PlaybackEvent::Repeat},
    {"filter_explicit_content_changed", PlaybackEvent::Filter},
    {"auto_play_changed", PlaybackEvent::AutoPlay},
    {"track_changed", PlaybackEvent::TrackChanged},
    {"play", PlaybackEvent::PlayingPaused},
    {"pause", PlaybackEvent::PlayingPaused},
    {"seeked", PlaybackEvent::PlayingPaused},
    {"position_correction", PlaybackEvent::PlayingPaused},
    {"unavailable", PlaybackEvent::TrackChanging},
    {"end_of_track", PlaybackEvent::TrackChanging},
    {"preload_next", PlaybackEvent::TrackChanging},
    {"preloading", PlaybackEvent::TrackChanging},
    {"loading", PlaybackEvent::TrackChanging},
    {"stopped", PlaybackEvent::TrackChanging}
};

PlaybackEvent stringToEvent(const std::string& sEvent);
void handlePlaybackEvent(const std::string& sEven);
