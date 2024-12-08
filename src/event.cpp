

#include "../headers/event.h"

//TODO: see if this can be optimised with std::string_view
ItemType TrackMap(const std::string& cEnvItemType) {
    if (cEnvItemType == "Track") return ItemType::Track;
    else if (cEnvItemType == "Episode") return ItemType::Episode;
    else return ItemType::Unknown  ;
};

std::vector<std::string> SplitUrls(const std::string& input) {
    std::vector<std::string> urls;
    std::istringstream iss(input);
    std::string url;
    
    while (std::getline(iss, url, '\n')) {
        if (!url.empty()) {
            urls.push_back(url);
        }
    }
    
    return urls;
};


PlaybackEvent StringToEvent(const std::string& sEvent) {

    // Trim whitespace from the input string
    std::string trimmedEvent = sEvent;
    trimmedEvent.erase(trimmedEvent.find_last_not_of(" \t\n\r\f\v") + 1);

    auto it = EventMap.find(trimmedEvent);
    return (it != EventMap.end()) ? it->second : PlaybackEvent::Unknown;
}

std::string nullHandler(const char* value, const std::string& defaultValue) {
    return value ? value : defaultValue;
}

// Function to handle playback events
nlohmann::json handlePlaybackEvent(const std::string& sEvent) {
    PlaybackEvent event = StringToEvent(sEvent);
    
    nlohmann::json payload;

    switch (event) {
        case PlaybackEvent::ConDisConnected:
            payload["Username"] = nullHandler(cEnvUsername, "Unknown");
            payload["connectionID"] = nullHandler(cEnvConnectionID , "Unknown");
            break;


        case PlaybackEvent::SessionClientChanged:
            payload["clientID"] = nullHandler(cEnvClientID, "Unknown");
            payload["clientName"] = nullHandler(cEnvClientName, "Unknown");
            payload["clientBrand"] = nullHandler(cEnvClientBrand, "Unknown");
            payload["clientModel"] = nullHandler(cEnvModel, "Unknown");
            break;
            

        case PlaybackEvent::TrackChanged:
            //common fields see env.h & env.cpp
            payload["type"] = nullHandler(cEnvItemType, "Unknown");
            payload["id"] = nullHandler(cEnvTrackId, "Unknown");
            payload["name"] = nullHandler(cEnvTrackName, "Unknown");
            payload["length"] = nullHandler(cEnvTrackLength, "0");

            payload["cover"] = SplitUrls(nullHandler( cEnvTrackCover , "Unknown"));
            payload["uri"] = nullHandler(cEnvTrackURI, "Unknown");
            payload["explicit"] = nullHandler(cEnvTrackExplicit, "0");
            payload["language"] = nullHandler(cEnvTrackLang, "en"); // match format

            //Music Track Specific
            if (TrackMap(cEnvItemType) == ItemType::Track){
                payload["trackNumber"] = nullHandler(cEnvTrackNumber, "0");
                payload["discNumber"] = nullHandler(cEnvDiscNumber, "0");
                payload["popularity"] = nullHandler(cEnvPopularity, "Unknown"); // match format

                payload["artistName"] = nullHandler(cEnvArtistName, "Unknown");
                payload["albumArtists"] = nullHandler(cEnvAlbumArtists, "Unknown");
                payload["albumName"] = nullHandler(cEnvAlbumName, "Unknown");
                
            }

            // Podcast/Episode Specific
            else if (TrackMap(cEnvItemType) == ItemType::Episode){
                payload["showName"] = nullHandler(cEnvShowName, "Unknown");
                payload["publishTime"] = nullHandler(cEnvShowPubTime, "0"); //match format
                payload["description"] = nullHandler(cEnvShowDesc, "Unknown");
            }
            break;
            
        case PlaybackEvent::PlayingPaused:
            payload["trackId"] = nullHandler(cEnvTrackId, "Unknown");
            payload ["position"] = nullHandler(cEnvPosition,"0");
            break;


        case PlaybackEvent::VolumeChanged:
            payload["volume"] = nullHandler(cEnvVolume,"0");
            break;

        case PlaybackEvent::Shuffle:
            payload["shuffle"] = nullHandler(cEnvShuffle,"0");
            break;
        case PlaybackEvent::Repeat:
            payload["repeat"] = nullHandler(cEnvRepeat,"0");
            break;
        
        case PlaybackEvent::AutoPlay:
            payload["autoPlay"] = nullHandler(cEnvAutoPlay,"0");
            break;

        case PlaybackEvent::Filter:
            payload["shuffle"] = nullHandler(cEnvFilter,"0");
            break;


        case PlaybackEvent::TrackStateChanging:
            payload["trackID"] = nullHandler(cEnvTrackId,"0");// just return track ID as there is no extra metadata
            break;


        case PlaybackEvent::Blocking:
            payload["sinkStatus"] = nullHandler(cEnvSinkStatus,"Unknown");
            break;

        
        default:
            std::cout << "Received Unknown event: " << sEvent << std::endl;
            break;
    }
    return payload;
}