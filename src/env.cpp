#include <cstdlib> // For std::getenv

//header imports
#include "../headers/env.h"


// Retrieve environment variables
const char* cEnvPlayerEvent = std::getenv("PLAYER_EVENT");


// Track Common 
const char* cEnvItemType = std::getenv("ITEM_TYPE");
const char* cEnvTrackId = std::getenv("TRACK_ID");
const char* cEnvTrackName = std::getenv("NAME");
const char* cEnvTrackLength = std::getenv("DURATION_MS");
const char* cEnvTrackCover = std::getenv("COVERS");
const char* cEnvTrackURI = std::getenv("URI");
const char* cEnvTrackExplicit = std::getenv("IS_EXPLICIT");
const char* cEnvTrackLang = std::getenv("LANGUAGE");

// Track Specific 
const char* cEnvTrackNumber = std::getenv("NUMBER");
const char* cEnvDiscNumber = std::getenv("DISC_NUMBER");
const char* cEnvPopularity = std::getenv("POPULARITY");

const char* cEnvArtistName = std::getenv("ARTISTS");
const char* cEnvAlbumArtists = std::getenv("ALBUM_ARTISTS");
const char* cEnvAlbumName = std::getenv("ALBUM_NAME");

// Podcast/ Episode Specific
const char* cEnvShowName = std::getenv("SHOW_NAME");
const char* cEnvShowPubTime = std::getenv("PUBLISH_TIME");
const char* cEnvShowDesc = std::getenv("DESCRIPTION");


// Play/ Pause/ Seek/ Position correction specific
// const char* cEnvTrackId = std::getenv("TRACK_ID"); in the payload but already defined
const char* cEnvPosition = std::getenv("POSITION_MS");

// Unavilable/ End of Track/ Preload Next/ PreLoading/ Stopped Specific
// const char* cEnvTrackId = std::getenv("TRACK_ID"); in the payload but already defined


// Session Specific

const char* cEnvUsername = std::getenv("USER_NAME");
const char* cEnvConnectionID = std::getenv("CONNECTION_ID");

// Client Specific
const char* cEnvClientID = std::getenv("CLIENT_ID");
const char* cEnvClientName = std::getenv("CLIENT_NAME");
const char* cEnvClientBrand = std::getenv("CLIENT_BRAND_NAME");
const char* cEnvModel = std::getenv("CLIENT_MODEL_NAME");


// Volume specific
const char* cEnvVolume = std::getenv("VOLUME");

// Shuffle specific
const char* cEnvShuffle = std::getenv("SHUFFLE");

// Repeat Specific
const char* cEnvRepeat = std::getenv("REPEAT");

// Auto Play Specific
// not currently working see: https://github.com/librespot-org/librespot/issues/1411
const char* cEnvAutoPlay = std::getenv("AUTO_PLAY");

// Explicit Specific
const char* cEnvFilter = std::getenv("FILTER");

const char* cEnvSinkStatus = std::getenv("SINK_STATUS");