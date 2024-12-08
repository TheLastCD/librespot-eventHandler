#include "../lib/json/single_include/nlohmann/json.hpp"

#include "../headers/env.h"

#include <string>
#include <unordered_map>
#include <iostream>


enum class PlaybackEvent {
    ConDisConnected,
    PlayingPaused,
    SessionClientChanged,
    TrackChanged, //this one expects metadata
    TrackStateChanging, // this one does not
    VolumeChanged,
    Shuffle,
    Repeat,
    Filter,
    AutoPlay,
    Blocking,
    Unknown
};

enum class ItemType {
    Track,
    Episode,
    Unknown
};





static const std::unordered_map<std::string, PlaybackEvent> EventMap  = {
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
    {"playing", PlaybackEvent::PlayingPaused},
    {"pause", PlaybackEvent::PlayingPaused},
    {"seeked", PlaybackEvent::PlayingPaused},
    {"position_correction", PlaybackEvent::PlayingPaused},
    {"unavailable", PlaybackEvent::TrackStateChanging},
    {"end_of_track", PlaybackEvent::TrackStateChanging},
    {"preload_next", PlaybackEvent::TrackStateChanging},
    {"preloading", PlaybackEvent::TrackStateChanging},
    {"loading", PlaybackEvent::TrackStateChanging},
    {"stopped", PlaybackEvent::TrackStateChanging},
    {"sink", PlaybackEvent::Blocking}
};


ItemType TrackMap(const std::string& cEnvItemType);
std::string nullHandler(const char* value, const std::string& defaultValue);
PlaybackEvent stringToEvent(const std::string& sEvent);
nlohmann::json handlePlaybackEvent(const std::string& sEvent);
