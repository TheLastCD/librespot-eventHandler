    #include <string>
    
    
    struct STrack {
        std::string m_TrackID;
        std::string m_TrackName;
        std::string m_TrackCover;
        std::string m_TrackURI;
        std::string m_TrackLength;
        std::string m_TrackNumber;
        std::string m_ArtistName;
        std::string m_AlbumName;

    };

    struct SEpisode {
        std::string m_ShowName;
        std::string m_PublishTime;
        std::string m_Desc;
    };

    struct SPlaying{
        std::string m_TrackID;
        std::string m_PositionMs;
    };