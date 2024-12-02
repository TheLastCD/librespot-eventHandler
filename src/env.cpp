#include <cstdlib> // For std::getenv

//header imports
#include "headers/env.h"


// Retrieve environment variables
const char* cEnvPlayerEvent = std::getenv("PLAYER_EVENT");
const char* cEnvItemType = std::getenv("ITEM_TYPE");

// Track Specific
const char* cEnvTrackId = std::getenv("TRACK_ID");
const char* cEnvTrackName = std::getenv("NAME");
const char* cEnvTrackNumber = std::getenv("NUMBER");
const char* cEnvTrackLength = std::getenv("DURATION_MS");
const char* cEnvTrackCover = std::getenv("COVERS");
const char* cEnvTrackURI = std::getenv("URI");
const char* cEnvTrackExplicit = std::getenv("IS_EXPLICIT");
const char* cEnvTrackLang = std::getenv("LANGUAGE");

// Album Specific
const char* cEnvArtistName = std::getenv("ARTISTS");
const char* cEnvAlbumArtists = std::getenv("ALBUM_ARTISTS");
const char* cEnvAlbumName = std::getenv("ALBUM_NAME");

// Podcast Specific
const char* cEnvShowName = std::getenv("SHOW_NAME");
const char* cEnvShowPubTime = std::getenv("PUBLISH_TIME");
const char* cEnvShowDesc = std::getenv("DESCRIPTION");



// Misc    
const char* cEnvDiscNumber = std::getenv("DISC_NUMBER");
const char* cEnvPopularity = std::getenv("POPULARITY");