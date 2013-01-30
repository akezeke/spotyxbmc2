#pragma once

#include "DynamicDll.h"
#undef byte

#ifndef SP_CALLCONV
#ifdef _WIN32
#define SP_CALLCONV __stdcall
#else
#define SP_CALLCONV
#endif
#endif
#ifndef SP_LIBEXPORT
#ifdef _WIN32
#define SP_LIBEXPORT(x) x __stdcall
#else
#define SP_LIBEXPORT(x) x
#endif
#endif
#include <stddef.h>
#ifdef _WIN32
typedef unsigned __int64 sp_uint64;
#else
#include <stdint.h>
typedef uint64_t sp_uint64;
#endif
#if !defined(__cplusplus) && !defined(__bool_true_false_are_defined)
typedef unsigned char bool;
#endif
typedef unsigned char byte;
typedef struct sp_session sp_session;
typedef struct sp_track sp_track;
typedef struct sp_album sp_album;
typedef struct sp_artist sp_artist;
typedef struct sp_artistbrowse sp_artistbrowse;
typedef struct sp_albumbrowse sp_albumbrowse;
typedef struct sp_toplistbrowse sp_toplistbrowse;
typedef struct sp_search sp_search;
typedef struct sp_link sp_link;
typedef struct sp_image sp_image;
typedef struct sp_user sp_user;
typedef struct sp_playlist sp_playlist;
typedef struct sp_playlistcontainer sp_playlistcontainer;
typedef struct sp_inbox sp_inbox;
typedef enum sp_error {
    SP_ERROR_OK                        = 0,
    SP_ERROR_BAD_API_VERSION           = 1,
    SP_ERROR_API_INITIALIZATION_FAILED = 2,
    SP_ERROR_TRACK_NOT_PLAYABLE        = 3,
    SP_ERROR_BAD_APPLICATION_KEY       = 5,
    SP_ERROR_BAD_USERNAME_OR_PASSWORD  = 6,
    SP_ERROR_USER_BANNED               = 7,
    SP_ERROR_UNABLE_TO_CONTACT_SERVER  = 8,
    SP_ERROR_CLIENT_TOO_OLD            = 9,
    SP_ERROR_OTHER_PERMANENT           = 10,
    SP_ERROR_BAD_USER_AGENT            = 11,
    SP_ERROR_MISSING_CALLBACK          = 12,
    SP_ERROR_INVALID_INDATA            = 13,
    SP_ERROR_INDEX_OUT_OF_RANGE        = 14,
    SP_ERROR_USER_NEEDS_PREMIUM        = 15,
    SP_ERROR_OTHER_TRANSIENT           = 16,
    SP_ERROR_IS_LOADING                = 17,
    SP_ERROR_NO_STREAM_AVAILABLE       = 18,
    SP_ERROR_PERMISSION_DENIED         = 19,
    SP_ERROR_INBOX_IS_FULL             = 20,
    SP_ERROR_NO_CACHE                  = 21,
    SP_ERROR_NO_SUCH_USER              = 22,
    SP_ERROR_NO_CREDENTIALS            = 23,
    SP_ERROR_NETWORK_DISABLED          = 24,
    SP_ERROR_INVALID_DEVICE_ID         = 25,
    SP_ERROR_CANT_OPEN_TRACE_FILE      = 26,
    SP_ERROR_APPLICATION_BANNED        = 27,
    SP_ERROR_OFFLINE_TOO_MANY_TRACKS   = 31,
    SP_ERROR_OFFLINE_DISK_CACHE        = 32,
    SP_ERROR_OFFLINE_EXPIRED           = 33,
    SP_ERROR_OFFLINE_NOT_ALLOWED       = 34,
    SP_ERROR_OFFLINE_LICENSE_LOST      = 35,
    SP_ERROR_OFFLINE_LICENSE_ERROR     = 36,
} sp_error;
#define SPOTIFY_API_VERSION 10
typedef enum sp_connectionstate {
    SP_CONNECTION_STATE_LOGGED_OUT   = 0,
    SP_CONNECTION_STATE_LOGGED_IN    = 1,
    SP_CONNECTION_STATE_DISCONNECTED = 2,
    SP_CONNECTION_STATE_UNDEFINED    = 3,
    SP_CONNECTION_STATE_OFFLINE		 = 4
} sp_connectionstate;
typedef enum sp_sampletype {
    SP_SAMPLETYPE_INT16_NATIVE_ENDIAN = 0,
} sp_sampletype;
typedef struct sp_audioformat {
    sp_sampletype sample_type;
    int sample_rate;
    int channels;
} sp_audioformat;
typedef enum sp_bitrate {
  SP_BITRATE_160k = 0,
  SP_BITRATE_320k = 1,
  SP_BITRATE_96k = 2,
} sp_bitrate;
typedef enum sp_playlist_type {
    SP_PLAYLIST_TYPE_PLAYLIST     = 0,
    SP_PLAYLIST_TYPE_START_FOLDER = 1,
    SP_PLAYLIST_TYPE_END_FOLDER   = 2,
    SP_PLAYLIST_TYPE_PLACEHOLDER  = 3,
} sp_playlist_type;
typedef enum sp_playlist_offline_status {
    SP_PLAYLIST_OFFLINE_STATUS_NO          = 0,
    SP_PLAYLIST_OFFLINE_STATUS_YES         = 1,
    SP_PLAYLIST_OFFLINE_STATUS_DOWNLOADING = 2,
    SP_PLAYLIST_OFFLINE_STATUS_WAITING     = 3,
} sp_playlist_offline_status;
typedef enum sp_availability {
    SP_TRACK_AVAILABILITY_UNAVAILABLE = 0,
    SP_TRACK_AVAILABILITY_AVAILABLE   = 1,
    SP_TRACK_AVAILABILITY_NOT_STREAMABLE = 2,
    SP_TRACK_AVAILABILITY_BANNED_BY_ARTIST = 3,
} sp_track_availability;
typedef enum sp_track_offline_status {
    SP_TRACK_OFFLINE_NO             = 0,
    SP_TRACK_OFFLINE_WAITING        = 1,
    SP_TRACK_OFFLINE_DOWNLOADING    = 2,
    SP_TRACK_OFFLINE_DONE           = 3,
    SP_TRACK_OFFLINE_ERROR          = 4,
    SP_TRACK_OFFLINE_DONE_EXPIRED   = 5,
    SP_TRACK_OFFLINE_LIMIT_EXCEEDED = 6,
    SP_TRACK_OFFLINE_DONE_RESYNC    = 7,
} sp_track_offline_status;
typedef struct sp_audio_buffer_stats {
    int samples;
    int stutter;
} sp_audio_buffer_stats;
typedef struct sp_subscribers {
    unsigned int count;
    char *subscribers[1];
} sp_subscribers;
typedef enum sp_connection_type {
    SP_CONNECTION_TYPE_UNKNOWN        = 0,
    SP_CONNECTION_TYPE_NONE           = 1,
    SP_CONNECTION_TYPE_MOBILE         = 2,
    SP_CONNECTION_TYPE_MOBILE_ROAMING = 3,
    SP_CONNECTION_TYPE_WIFI           = 4,
    SP_CONNECTION_TYPE_WIRED          = 5,
} sp_connection_type;
typedef enum sp_connection_rules {
    SP_CONNECTION_RULE_NETWORK                = 0x1,
    SP_CONNECTION_RULE_NETWORK_IF_ROAMING     = 0x2,
    SP_CONNECTION_RULE_ALLOW_SYNC_OVER_MOBILE = 0x4,
    SP_CONNECTION_RULE_ALLOW_SYNC_OVER_WIFI   = 0x8,
} sp_connection_rules;
typedef enum sp_artistbrowse_type {
    SP_ARTISTBROWSE_FULL,
    SP_ARTISTBROWSE_NO_TRACKS,
    SP_ARTISTBROWSE_NO_ALBUMS,
} sp_artistbrowse_type;
typedef struct sp_offline_sync_status {
    int queued_tracks;
    sp_uint64 queued_bytes;
    int done_tracks;
    sp_uint64 done_bytes;
    int copied_tracks;
    sp_uint64 copied_bytes;
    int willnotcopy_tracks;
    int error_tracks;
    bool syncing;
} sp_offline_sync_status;
typedef struct sp_session_callbacks {
    void (SP_CALLCONV *logged_in)(sp_session *session, sp_error error);
    void (SP_CALLCONV *logged_out)(sp_session *session);
    void (SP_CALLCONV *metadata_updated)(sp_session *session);
    void (SP_CALLCONV *connection_error)(sp_session *session, sp_error error);
    void (SP_CALLCONV *message_to_user)(sp_session *session, const char *message);
    void (SP_CALLCONV *notify_main_thread)(sp_session *session);
    int (SP_CALLCONV *music_delivery)(sp_session *session, const sp_audioformat *format, const void *frames, int num_frames);
    void (SP_CALLCONV *play_token_lost)(sp_session *session);
    void (SP_CALLCONV *log_message)(sp_session *session, const char *data);
    void (SP_CALLCONV *end_of_track)(sp_session *session);
    void (SP_CALLCONV *streaming_error)(sp_session *session, sp_error error);
    void (SP_CALLCONV *userinfo_updated)(sp_session *session);
    void (SP_CALLCONV *start_playback)(sp_session *session);
    void (SP_CALLCONV *stop_playback)(sp_session *session);
    void (SP_CALLCONV *get_audio_buffer_stats)(sp_session *session, sp_audio_buffer_stats *stats);
    void (SP_CALLCONV *offline_status_updated)(sp_session *session);
    void (SP_CALLCONV *offline_error)(sp_session *session, sp_error error);
} sp_session_callbacks;
typedef struct sp_session_config {
    int api_version;
    const char *cache_location;
    const char *settings_location;
    const void *application_key;
    size_t application_key_size;
    const char *user_agent;
    const sp_session_callbacks *callbacks;
    void *userdata;
    bool compress_playlists;
    bool dont_save_metadata_for_playlists;
    bool initially_unload_playlists;
    const char *device_id;
    const char *tracefile;
} sp_session_config;
typedef enum {
    SP_LINKTYPE_INVALID  = 0,
    SP_LINKTYPE_TRACK    = 1,
    SP_LINKTYPE_ALBUM    = 2,
    SP_LINKTYPE_ARTIST   = 3,
    SP_LINKTYPE_SEARCH   = 4,
    SP_LINKTYPE_PLAYLIST = 5,
    SP_LINKTYPE_PROFILE  = 6,
    SP_LINKTYPE_STARRED  = 7,
    SP_LINKTYPE_LOCALTRACK  = 8,
    SP_LINKTYPE_IMAGE = 9,
} sp_linktype;
typedef enum {
    SP_ALBUMTYPE_ALBUM       = 0,
    SP_ALBUMTYPE_SINGLE      = 1,
    SP_ALBUMTYPE_COMPILATION = 2,
    SP_ALBUMTYPE_UNKNOWN     = 3,
} sp_albumtype;
typedef void SP_CALLCONV albumbrowse_complete_cb(sp_albumbrowse *result, void *userdata);
typedef void SP_CALLCONV artistbrowse_complete_cb(sp_artistbrowse *result, void *userdata);
typedef enum {
    SP_IMAGE_FORMAT_UNKNOWN = -1,
    SP_IMAGE_FORMAT_JPEG   = 0,
} sp_imageformat;
typedef void SP_CALLCONV image_loaded_cb(sp_image *image, void *userdata);
typedef enum sp_radio_genre {
  SP_RADIO_GENRE_ALT_POP_ROCK = 0x1,
  SP_RADIO_GENRE_BLUES        = 0x2,
  SP_RADIO_GENRE_COUNTRY      = 0x4,
  SP_RADIO_GENRE_DISCO        = 0x8,
  SP_RADIO_GENRE_FUNK         = 0x10,
  SP_RADIO_GENRE_HARD_ROCK    = 0x20,
  SP_RADIO_GENRE_HEAVY_METAL  = 0x40,
  SP_RADIO_GENRE_RAP          = 0x80,
  SP_RADIO_GENRE_HOUSE        = 0x100,
  SP_RADIO_GENRE_JAZZ         = 0x200,
  SP_RADIO_GENRE_NEW_WAVE     = 0x400,
  SP_RADIO_GENRE_RNB          = 0x800,
  SP_RADIO_GENRE_POP          = 0x1000,
  SP_RADIO_GENRE_PUNK         = 0x2000,
  SP_RADIO_GENRE_REGGAE       = 0x4000,
  SP_RADIO_GENRE_POP_ROCK     = 0x8000,
  SP_RADIO_GENRE_SOUL         = 0x10000,
  SP_RADIO_GENRE_TECHNO       = 0x20000,
} sp_radio_genre;
typedef void SP_CALLCONV search_complete_cb(sp_search *result, void *userdata);
typedef struct sp_playlist_callbacks {
    void (SP_CALLCONV *tracks_added)(sp_playlist *pl, sp_track * const *tracks, int num_tracks, int position, void *userdata);
    void (SP_CALLCONV *tracks_removed)(sp_playlist *pl, const int *tracks, int num_tracks, void *userdata);
    void (SP_CALLCONV *tracks_moved)(sp_playlist *pl, const int *tracks, int num_tracks, int new_position, void *userdata);
    void (SP_CALLCONV *playlist_renamed)(sp_playlist *pl, void *userdata);
    void (SP_CALLCONV *playlist_state_changed)(sp_playlist *pl, void *userdata);
    void (SP_CALLCONV *playlist_update_in_progress)(sp_playlist *pl, bool done, void *userdata);
    void (SP_CALLCONV *playlist_metadata_updated)(sp_playlist *pl, void *userdata);
    void (SP_CALLCONV *track_created_changed)(sp_playlist *pl, int position, sp_user *user, int when, void *userdata);
    void (SP_CALLCONV *track_seen_changed)(sp_playlist *pl, int position, bool seen, void *userdata);
    void (SP_CALLCONV *description_changed)(sp_playlist *pl, const char *desc, void *userdata);
    void (SP_CALLCONV *image_changed)(sp_playlist *pl, const byte *image, void *userdata);
    void (SP_CALLCONV *track_message_changed)(sp_playlist *pl, int position, const char *message, void *userdata);
    void (SP_CALLCONV *subscribers_changed)(sp_playlist *pl, void *userdata);
} sp_playlist_callbacks;
typedef struct sp_playlistcontainer_callbacks {
    void (SP_CALLCONV *playlist_added)(sp_playlistcontainer *pc, sp_playlist *playlist, int position, void *userdata);
    void (SP_CALLCONV *playlist_removed)(sp_playlistcontainer *pc, sp_playlist *playlist, int position, void *userdata);
    void (SP_CALLCONV *playlist_moved)(sp_playlistcontainer *pc, sp_playlist *playlist, int position, int new_position, void *userdata);
    void (SP_CALLCONV *container_loaded)(sp_playlistcontainer *pc, void *userdata);
} sp_playlistcontainer_callbacks;
typedef enum sp_relation_type {
  SP_RELATION_TYPE_UNKNOWN = 0,
  SP_RELATION_TYPE_NONE = 1,
  SP_RELATION_TYPE_UNIDIRECTIONAL = 2,
  SP_RELATION_TYPE_BIDIRECTIONAL = 3,
} sp_relation_type;
typedef enum {
    SP_TOPLIST_TYPE_ARTISTS = 0,
    SP_TOPLIST_TYPE_ALBUMS  = 1,
    SP_TOPLIST_TYPE_TRACKS  = 2,
} sp_toplisttype;
#define SP_TOPLIST_REGION(a, b) ((a) << 8 | (b))
typedef enum {
    SP_TOPLIST_REGION_EVERYWHERE = 0,
    SP_TOPLIST_REGION_USER = 1,
} sp_toplistregion;
typedef void SP_CALLCONV toplistbrowse_complete_cb(sp_toplistbrowse *result, void *userdata);
typedef void SP_CALLCONV inboxpost_complete_cb(sp_inbox *result, void *userdata);

class DllLibspotifyInterface
{
public:
    virtual ~DllLibspotifyInterface() {}

    virtual const char* sp_error_message(sp_error ) = 0;
    virtual sp_error sp_session_create(const sp_session_config *, sp_session **) = 0;
    virtual void sp_session_release(sp_session *) = 0;
    virtual void sp_session_login(sp_session *, const char *, const char *, bool ) = 0;
    virtual sp_error sp_session_relogin(sp_session *) = 0;
    virtual int sp_session_remembered_user(sp_session *, char *, size_t ) = 0;
    virtual void sp_session_forget_me(sp_session *) = 0;
    virtual sp_user * sp_session_user(sp_session *) = 0;
    virtual void sp_session_logout(sp_session *) = 0;
    virtual sp_connectionstate sp_session_connectionstate(sp_session *) = 0;
    virtual void * sp_session_userdata(sp_session *) = 0;
    virtual void sp_session_set_cache_size(sp_session *, size_t ) = 0;
    virtual void sp_session_process_events(sp_session *, int *) = 0;
    virtual sp_error sp_session_player_load(sp_session *, sp_track *) = 0;
    virtual void sp_session_player_seek(sp_session *, int ) = 0;
    virtual void sp_session_player_play(sp_session *, bool ) = 0;
    virtual void sp_session_player_unload(sp_session *) = 0;
    virtual sp_error sp_session_player_prefetch(sp_session *, sp_track *) = 0;
    virtual sp_playlistcontainer * sp_session_playlistcontainer(sp_session *) = 0;
    virtual sp_playlist * sp_session_inbox_create(sp_session *) = 0;
    virtual sp_playlist * sp_session_starred_create(sp_session *) = 0;
    virtual sp_playlist * sp_session_starred_for_user_create(sp_session *, const char *) = 0;
    virtual sp_playlistcontainer * sp_session_publishedcontainer_for_user_create(sp_session *, const char *) = 0;
    virtual void sp_session_preferred_bitrate(sp_session *, sp_bitrate ) = 0;
    virtual void sp_session_preferred_offline_bitrate(sp_session *, sp_bitrate , bool ) = 0;
    virtual bool sp_session_get_volume_normalization(sp_session *) = 0;
    virtual void sp_session_set_volume_normalization(sp_session *, bool ) = 0;
    virtual void sp_session_set_connection_type(sp_session *, sp_connection_type ) = 0;
    virtual void sp_session_set_connection_rules(sp_session *, sp_connection_rules ) = 0;
    virtual int sp_offline_tracks_to_sync(sp_session *) = 0;
    virtual int sp_offline_num_playlists(sp_session *) = 0;
    virtual bool sp_offline_sync_get_status(sp_session *, sp_offline_sync_status *) = 0;
    virtual int sp_offline_time_left(sp_session *) = 0;
    virtual int sp_session_user_country(sp_session *) = 0;
    virtual sp_link * sp_link_create_from_string(const char *) = 0;
    virtual sp_link * sp_link_create_from_track(sp_track *, int ) = 0;
    virtual sp_link * sp_link_create_from_album(sp_album *) = 0;
    virtual sp_link * sp_link_create_from_album_cover(sp_album *) = 0;
    virtual sp_link * sp_link_create_from_artist(sp_artist *) = 0;
    virtual sp_link * sp_link_create_from_artist_portrait(sp_artist *) = 0;
    virtual sp_link * sp_link_create_from_artistbrowse_portrait(sp_artistbrowse *, int ) = 0;
    virtual sp_link * sp_link_create_from_search(sp_search *) = 0;
    virtual sp_link * sp_link_create_from_playlist(sp_playlist *) = 0;
    virtual sp_link * sp_link_create_from_user(sp_user *) = 0;
    virtual sp_link * sp_link_create_from_image(sp_image *) = 0;
    virtual int sp_link_as_string(sp_link *, char *, int ) = 0;
    virtual sp_linktype sp_link_type(sp_link *) = 0;
    virtual sp_track * sp_link_as_track(sp_link *) = 0;
    virtual sp_track * sp_link_as_track_and_offset(sp_link *, int *) = 0;
    virtual sp_album * sp_link_as_album(sp_link *) = 0;
    virtual sp_artist * sp_link_as_artist(sp_link *) = 0;
    virtual sp_user * sp_link_as_user(sp_link *) = 0;
    virtual void sp_link_add_ref(sp_link *) = 0;
    virtual void sp_link_release(sp_link *) = 0;
    virtual bool sp_track_is_loaded(sp_track *) = 0;
    virtual sp_error sp_track_error(sp_track *) = 0;
    virtual sp_track_offline_status sp_track_offline_get_status(sp_track *) = 0;
    virtual sp_track_availability sp_track_get_availability(sp_session *, sp_track *) = 0;
    virtual bool sp_track_is_local(sp_session *, sp_track *) = 0;
    virtual bool sp_track_is_autolinked(sp_session *, sp_track *) = 0;
    virtual bool sp_track_is_placeholder(sp_track *) = 0;
    virtual bool sp_track_is_starred(sp_session *, sp_track *) = 0;
    virtual void sp_track_set_starred(sp_session *, sp_track *const*, int , bool ) = 0;
    virtual int sp_track_num_artists(sp_track *) = 0;
    virtual sp_artist * sp_track_artist(sp_track *, int ) = 0;
    virtual sp_album * sp_track_album(sp_track *) = 0;
    virtual const char * sp_track_name(sp_track *) = 0;
    virtual int sp_track_duration(sp_track *) = 0;
    virtual int sp_track_popularity(sp_track *) = 0;
    virtual int sp_track_disc(sp_track *) = 0;
    virtual int sp_track_index(sp_track *) = 0;
    virtual sp_track * sp_localtrack_create(const char *, const char *, const char *, int ) = 0;
    virtual void sp_track_add_ref(sp_track *) = 0;
    virtual void sp_track_release(sp_track *) = 0;
    virtual bool sp_album_is_loaded(sp_album *) = 0;
    virtual bool sp_album_is_available(sp_album *) = 0;
    virtual sp_artist * sp_album_artist(sp_album *) = 0;
    virtual const byte * sp_album_cover(sp_album *) = 0;
    virtual const char * sp_album_name(sp_album *) = 0;
    virtual int sp_album_year(sp_album *) = 0;
    virtual sp_albumtype sp_album_type(sp_album *) = 0;
    virtual void sp_album_add_ref(sp_album *) = 0;
    virtual void sp_album_release(sp_album *) = 0;
    virtual const char * sp_artist_name(sp_artist *) = 0;
    virtual bool sp_artist_is_loaded(sp_artist *) = 0;
    virtual const byte * sp_artist_portrait(sp_artist *) = 0;
    virtual void sp_artist_add_ref(sp_artist *) = 0;
    virtual void sp_artist_release(sp_artist *) = 0;
    virtual sp_albumbrowse * sp_albumbrowse_create(sp_session *, sp_album *, albumbrowse_complete_cb *, void *) = 0;
    virtual bool sp_albumbrowse_is_loaded(sp_albumbrowse *) = 0;
    virtual sp_error sp_albumbrowse_error(sp_albumbrowse *) = 0;
    virtual sp_album * sp_albumbrowse_album(sp_albumbrowse *) = 0;
    virtual sp_artist * sp_albumbrowse_artist(sp_albumbrowse *) = 0;
    virtual int sp_albumbrowse_num_copyrights(sp_albumbrowse *) = 0;
    virtual const char * sp_albumbrowse_copyright(sp_albumbrowse *, int ) = 0;
    virtual int sp_albumbrowse_num_tracks(sp_albumbrowse *) = 0;
    virtual sp_track * sp_albumbrowse_track(sp_albumbrowse *, int ) = 0;
    virtual const char * sp_albumbrowse_review(sp_albumbrowse *) = 0;
    virtual int sp_albumbrowse_backend_request_duration(sp_albumbrowse *) = 0;
    virtual void sp_albumbrowse_add_ref(sp_albumbrowse *) = 0;
    virtual void sp_albumbrowse_release(sp_albumbrowse *) = 0;
    virtual sp_artistbrowse * sp_artistbrowse_create(sp_session *, sp_artist *, sp_artistbrowse_type , artistbrowse_complete_cb *, void *) = 0;
    virtual bool sp_artistbrowse_is_loaded(sp_artistbrowse *) = 0;
    virtual sp_error sp_artistbrowse_error(sp_artistbrowse *) = 0;
    virtual sp_artist * sp_artistbrowse_artist(sp_artistbrowse *) = 0;
    virtual int sp_artistbrowse_num_portraits(sp_artistbrowse *) = 0;
    virtual const byte * sp_artistbrowse_portrait(sp_artistbrowse *, int ) = 0;
    virtual int sp_artistbrowse_num_tracks(sp_artistbrowse *) = 0;
    virtual sp_track * sp_artistbrowse_track(sp_artistbrowse *, int ) = 0;
    virtual int sp_artistbrowse_num_albums(sp_artistbrowse *) = 0;
    virtual sp_album * sp_artistbrowse_album(sp_artistbrowse *, int ) = 0;
    virtual int sp_artistbrowse_num_similar_artists(sp_artistbrowse *) = 0;
    virtual sp_artist * sp_artistbrowse_similar_artist(sp_artistbrowse *, int ) = 0;
    virtual const char * sp_artistbrowse_biography(sp_artistbrowse *) = 0;
    virtual int sp_artistbrowse_backend_request_duration(sp_artistbrowse *) = 0;
    virtual void sp_artistbrowse_add_ref(sp_artistbrowse *) = 0;
    virtual void sp_artistbrowse_release(sp_artistbrowse *) = 0;
    virtual sp_image * sp_image_create(sp_session *, const byte image_id[20]) = 0;
    virtual sp_image * sp_image_create_from_link(sp_session *, sp_link *) = 0;
    virtual void sp_image_add_load_callback(sp_image *, image_loaded_cb *, void *) = 0;
    virtual void sp_image_remove_load_callback(sp_image *, image_loaded_cb *, void *) = 0;
    virtual bool sp_image_is_loaded(sp_image *) = 0;
    virtual sp_error sp_image_error(sp_image *) = 0;
    virtual sp_imageformat sp_image_format(sp_image *) = 0;
    virtual const void * sp_image_data(sp_image *, size_t *) = 0;
    virtual const byte * sp_image_image_id(sp_image *) = 0;
    virtual void sp_image_add_ref(sp_image *) = 0;
    virtual void sp_image_release(sp_image *) = 0;
    virtual sp_search * sp_search_create(sp_session *, const char *, int , int , int , int , int , int , search_complete_cb *, void *) = 0;
    virtual sp_search * sp_radio_search_create(sp_session *, unsigned int , unsigned int , sp_radio_genre , search_complete_cb *, void *) = 0;
    virtual bool sp_search_is_loaded(sp_search *) = 0;
    virtual sp_error sp_search_error(sp_search *) = 0;
    virtual int sp_search_num_tracks(sp_search *) = 0;
    virtual sp_track * sp_search_track(sp_search *, int ) = 0;
    virtual int sp_search_num_albums(sp_search *) = 0;
    virtual sp_album * sp_search_album(sp_search *, int ) = 0;
    virtual int sp_search_num_artists(sp_search *) = 0;
    virtual sp_artist * sp_search_artist(sp_search *, int ) = 0;
    virtual const char * sp_search_query(sp_search *) = 0;
    virtual const char * sp_search_did_you_mean(sp_search *) = 0;
    virtual int sp_search_total_tracks(sp_search *) = 0;
    virtual int sp_search_total_albums(sp_search *) = 0;
    virtual int sp_search_total_artists(sp_search *) = 0;
    virtual void sp_search_add_ref(sp_search *) = 0;
    virtual void sp_search_release(sp_search *) = 0;
    virtual bool sp_playlist_is_loaded(sp_playlist *) = 0;
    virtual void sp_playlist_add_callbacks(sp_playlist *, sp_playlist_callbacks *, void *) = 0;
    virtual void sp_playlist_remove_callbacks(sp_playlist *, sp_playlist_callbacks *, void *) = 0;
    virtual int sp_playlist_num_tracks(sp_playlist *) = 0;
    virtual sp_track * sp_playlist_track(sp_playlist *, int ) = 0;
    virtual int sp_playlist_track_create_time(sp_playlist *, int ) = 0;
    virtual sp_user * sp_playlist_track_creator(sp_playlist *, int ) = 0;
    virtual bool sp_playlist_track_seen(sp_playlist *, int ) = 0;
    virtual sp_error sp_playlist_track_set_seen(sp_playlist *, int , bool ) = 0;
    virtual const char * sp_playlist_track_message(sp_playlist *, int ) = 0;
    virtual const char * sp_playlist_name(sp_playlist *) = 0;
    virtual sp_error sp_playlist_rename(sp_playlist *, const char *) = 0;
    virtual sp_user * sp_playlist_owner(sp_playlist *) = 0;
    virtual bool sp_playlist_is_collaborative(sp_playlist *) = 0;
    virtual void sp_playlist_set_collaborative(sp_playlist *, bool ) = 0;
    virtual void sp_playlist_set_autolink_tracks(sp_playlist *, bool ) = 0;
    virtual const char * sp_playlist_get_description(sp_playlist *) = 0;
    virtual bool sp_playlist_get_image(sp_playlist *, byte image[20]) = 0;
    virtual bool sp_playlist_has_pending_changes(sp_playlist *) = 0;
    virtual sp_error sp_playlist_add_tracks(sp_playlist *, sp_track *const*, int , int , sp_session *) = 0;
    virtual sp_error sp_playlist_remove_tracks(sp_playlist *, const int *, int ) = 0;
    virtual sp_error sp_playlist_reorder_tracks(sp_playlist *, const int *, int , int ) = 0;
    virtual unsigned int sp_playlist_num_subscribers(sp_playlist *) = 0;
    virtual sp_subscribers * sp_playlist_subscribers(sp_playlist *) = 0;
    virtual void sp_playlist_subscribers_free(sp_subscribers *) = 0;
    virtual void sp_playlist_update_subscribers(sp_session *, sp_playlist *) = 0;
    virtual bool sp_playlist_is_in_ram(sp_session *, sp_playlist *) = 0;
    virtual void sp_playlist_set_in_ram(sp_session *, sp_playlist *, bool ) = 0;
    virtual sp_playlist * sp_playlist_create(sp_session *, sp_link *) = 0;
    virtual void sp_playlist_set_offline_mode(sp_session *, sp_playlist *, bool ) = 0;
    virtual sp_playlist_offline_status sp_playlist_get_offline_status(sp_session *, sp_playlist *) = 0;
    virtual int sp_playlist_get_offline_download_completed(sp_session *, sp_playlist *) = 0;
    virtual void sp_playlist_add_ref(sp_playlist *) = 0;
    virtual void sp_playlist_release(sp_playlist *) = 0;
    virtual void sp_playlistcontainer_add_callbacks(sp_playlistcontainer *, sp_playlistcontainer_callbacks *, void *) = 0;
    virtual void sp_playlistcontainer_remove_callbacks(sp_playlistcontainer *, sp_playlistcontainer_callbacks *, void *) = 0;
    virtual int sp_playlistcontainer_num_playlists(sp_playlistcontainer *) = 0;
    virtual bool sp_playlistcontainer_is_loaded(sp_playlistcontainer *) = 0;
    virtual sp_playlist * sp_playlistcontainer_playlist(sp_playlistcontainer *, int ) = 0;
    virtual sp_playlist_type sp_playlistcontainer_playlist_type(sp_playlistcontainer *, int ) = 0;
    virtual sp_error sp_playlistcontainer_playlist_folder_name(sp_playlistcontainer *, int , char *, int ) = 0;
    virtual sp_uint64 sp_playlistcontainer_playlist_folder_id(sp_playlistcontainer *, int ) = 0;
    virtual sp_playlist * sp_playlistcontainer_add_new_playlist(sp_playlistcontainer *, const char *) = 0;
    virtual sp_playlist * sp_playlistcontainer_add_playlist(sp_playlistcontainer *, sp_link *) = 0;
    virtual sp_error sp_playlistcontainer_remove_playlist(sp_playlistcontainer *, int ) = 0;
    virtual sp_error sp_playlistcontainer_move_playlist(sp_playlistcontainer *, int , int , bool ) = 0;
    virtual sp_error sp_playlistcontainer_add_folder(sp_playlistcontainer *, int , const char *) = 0;
    virtual sp_user * sp_playlistcontainer_owner(sp_playlistcontainer *) = 0;
    virtual void sp_playlistcontainer_add_ref(sp_playlistcontainer *) = 0;
    virtual void sp_playlistcontainer_release(sp_playlistcontainer *) = 0;
    virtual const char * sp_user_canonical_name(sp_user *) = 0;
    virtual const char * sp_user_display_name(sp_user *) = 0;
    virtual bool sp_user_is_loaded(sp_user *) = 0;
    virtual void sp_user_add_ref(sp_user *) = 0;
    virtual void sp_user_release(sp_user *) = 0;
    virtual sp_toplistbrowse * sp_toplistbrowse_create(sp_session *, sp_toplisttype , sp_toplistregion , const char *, toplistbrowse_complete_cb *, void *) = 0;
    virtual bool sp_toplistbrowse_is_loaded(sp_toplistbrowse *) = 0;
    virtual sp_error sp_toplistbrowse_error(sp_toplistbrowse *) = 0;
    virtual void sp_toplistbrowse_add_ref(sp_toplistbrowse *) = 0;
    virtual void sp_toplistbrowse_release(sp_toplistbrowse *) = 0;
    virtual int sp_toplistbrowse_num_artists(sp_toplistbrowse *) = 0;
    virtual sp_artist * sp_toplistbrowse_artist(sp_toplistbrowse *, int ) = 0;
    virtual int sp_toplistbrowse_num_albums(sp_toplistbrowse *) = 0;
    virtual sp_album * sp_toplistbrowse_album(sp_toplistbrowse *, int ) = 0;
    virtual int sp_toplistbrowse_num_tracks(sp_toplistbrowse *) = 0;
    virtual sp_track * sp_toplistbrowse_track(sp_toplistbrowse *, int ) = 0;
    virtual int sp_toplistbrowse_backend_request_duration(sp_toplistbrowse *) = 0;
    virtual sp_inbox * sp_inbox_post_tracks(sp_session *, const char *, sp_track * const *, int , const char *, inboxpost_complete_cb *, void *) = 0;
    virtual sp_error sp_inbox_error(sp_inbox *) = 0;
    virtual void sp_inbox_add_ref(sp_inbox *) = 0;
    virtual void sp_inbox_release(sp_inbox *) = 0;
    virtual const char * sp_build_id(void) = 0;
};

class DllLibspotify : public DllDynamic, DllLibspotifyInterface
{
    DECLARE_DLL_WRAPPER(DllLibspotify, "libspotify.so")

    DEFINE_METHOD1(const char*, sp_error_message, (sp_error p1))
    DEFINE_METHOD2(sp_error, sp_session_create, (const sp_session_config *p1, sp_session **p2))
    DEFINE_METHOD1(void, sp_session_release, (sp_session *p1))
    DEFINE_METHOD4(void, sp_session_login, (sp_session *p1, const char *p2, const char *p3, bool p4))
    DEFINE_METHOD1(sp_error, sp_session_relogin, (sp_session *p1))
    DEFINE_METHOD3(int, sp_session_remembered_user, (sp_session *p1, char *p2, size_t p3))
    DEFINE_METHOD1(void, sp_session_forget_me, (sp_session *p1))
    DEFINE_METHOD1(sp_user *, sp_session_user, (sp_session *p1))
    DEFINE_METHOD1(void, sp_session_logout, (sp_session *p1))
    DEFINE_METHOD1(sp_connectionstate, sp_session_connectionstate, (sp_session *p1))
    DEFINE_METHOD1(void *, sp_session_userdata, (sp_session *p1))
    DEFINE_METHOD2(void, sp_session_set_cache_size, (sp_session *p1, size_t p2))
    DEFINE_METHOD2(void, sp_session_process_events, (sp_session *p1, int *p2))
    DEFINE_METHOD2(sp_error, sp_session_player_load, (sp_session *p1, sp_track *p2))
    DEFINE_METHOD2(void, sp_session_player_seek, (sp_session *p1, int p2))
    DEFINE_METHOD2(void, sp_session_player_play, (sp_session *p1, bool p2))
    DEFINE_METHOD1(void, sp_session_player_unload, (sp_session *p1))
    DEFINE_METHOD2(sp_error, sp_session_player_prefetch, (sp_session *p1, sp_track *p2))
    DEFINE_METHOD1(sp_playlistcontainer *, sp_session_playlistcontainer, (sp_session *p1))
    DEFINE_METHOD1(sp_playlist *, sp_session_inbox_create, (sp_session *p1))
    DEFINE_METHOD1(sp_playlist *, sp_session_starred_create, (sp_session *p1))
    DEFINE_METHOD2(sp_playlist *, sp_session_starred_for_user_create, (sp_session *p1, const char *p2))
    DEFINE_METHOD2(sp_playlistcontainer *, sp_session_publishedcontainer_for_user_create, (sp_session *p1, const char *p2))
    DEFINE_METHOD2(void, sp_session_preferred_bitrate, (sp_session *p1, sp_bitrate p2))
    DEFINE_METHOD3(void, sp_session_preferred_offline_bitrate, (sp_session *p1, sp_bitrate p2, bool p3))
    DEFINE_METHOD1(bool, sp_session_get_volume_normalization, (sp_session *p1))
    DEFINE_METHOD2(void, sp_session_set_volume_normalization, (sp_session *p1, bool p2))
    DEFINE_METHOD2(void, sp_session_set_connection_type, (sp_session *p1, sp_connection_type p2))
    DEFINE_METHOD2(void, sp_session_set_connection_rules, (sp_session *p1, sp_connection_rules p2))
    DEFINE_METHOD1(int, sp_offline_tracks_to_sync, (sp_session *p1))
    DEFINE_METHOD1(int, sp_offline_num_playlists, (sp_session *p1))
    DEFINE_METHOD2(bool, sp_offline_sync_get_status, (sp_session *p1, sp_offline_sync_status *p2))
    DEFINE_METHOD1(int, sp_offline_time_left, (sp_session *p1))
    DEFINE_METHOD1(int, sp_session_user_country, (sp_session *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_string, (const char *p1))
    DEFINE_METHOD2(sp_link *, sp_link_create_from_track, (sp_track *p1, int p2))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_album, (sp_album *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_album_cover, (sp_album *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_artist, (sp_artist *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_artist_portrait, (sp_artist *p1))
    DEFINE_METHOD2(sp_link *, sp_link_create_from_artistbrowse_portrait, (sp_artistbrowse *p1, int p2))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_search, (sp_search *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_playlist, (sp_playlist *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_user, (sp_user *p1))
    DEFINE_METHOD1(sp_link *, sp_link_create_from_image, (sp_image *p1))
    DEFINE_METHOD3(int, sp_link_as_string, (sp_link *p1, char *p2, int p3))
    DEFINE_METHOD1(sp_linktype, sp_link_type, (sp_link *p1))
    DEFINE_METHOD1(sp_track *, sp_link_as_track, (sp_link *p1))
    DEFINE_METHOD2(sp_track *, sp_link_as_track_and_offset, (sp_link *p1, int *p2))
    DEFINE_METHOD1(sp_album *, sp_link_as_album, (sp_link *p1))
    DEFINE_METHOD1(sp_artist *, sp_link_as_artist, (sp_link *p1))
    DEFINE_METHOD1(sp_user *, sp_link_as_user, (sp_link *p1))
    DEFINE_METHOD1(void, sp_link_add_ref, (sp_link *p1))
    DEFINE_METHOD1(void, sp_link_release, (sp_link *p1))
    DEFINE_METHOD1(bool, sp_track_is_loaded, (sp_track *p1))
    DEFINE_METHOD1(sp_error, sp_track_error, (sp_track *p1))
    DEFINE_METHOD1(sp_track_offline_status, sp_track_offline_get_status, (sp_track *p1))
    DEFINE_METHOD2(sp_track_availability, sp_track_get_availability, (sp_session *p1, sp_track *p2))
    DEFINE_METHOD2(bool, sp_track_is_local, (sp_session *p1, sp_track *p2))
    DEFINE_METHOD2(bool, sp_track_is_autolinked, (sp_session *p1, sp_track *p2))
    DEFINE_METHOD1(bool, sp_track_is_placeholder, (sp_track *p1))
    DEFINE_METHOD2(bool, sp_track_is_starred, (sp_session *p1, sp_track *p2))
    DEFINE_METHOD4(void, sp_track_set_starred, (sp_session *p1, sp_track *const*p2, int p3, bool p4))
    DEFINE_METHOD1(int, sp_track_num_artists, (sp_track *p1))
    DEFINE_METHOD2(sp_artist *, sp_track_artist, (sp_track *p1, int p2))
    DEFINE_METHOD1(sp_album *, sp_track_album, (sp_track *p1))
    DEFINE_METHOD1(const char *, sp_track_name, (sp_track *p1))
    DEFINE_METHOD1(int, sp_track_duration, (sp_track *p1))
    DEFINE_METHOD1(int, sp_track_popularity, (sp_track *p1))
    DEFINE_METHOD1(int, sp_track_disc, (sp_track *p1))
    DEFINE_METHOD1(int, sp_track_index, (sp_track *p1))
    DEFINE_METHOD4(sp_track *, sp_localtrack_create, (const char *p1, const char *p2, const char *p3, int p4))
    DEFINE_METHOD1(void, sp_track_add_ref, (sp_track *p1))
    DEFINE_METHOD1(void, sp_track_release, (sp_track *p1))
    DEFINE_METHOD1(bool, sp_album_is_loaded, (sp_album *p1))
    DEFINE_METHOD1(bool, sp_album_is_available, (sp_album *p1))
    DEFINE_METHOD1(sp_artist *, sp_album_artist, (sp_album *p1))
    DEFINE_METHOD1(const byte *, sp_album_cover, (sp_album *p1))
    DEFINE_METHOD1(const char *, sp_album_name, (sp_album *p1))
    DEFINE_METHOD1(int, sp_album_year, (sp_album *p1))
    DEFINE_METHOD1(sp_albumtype, sp_album_type, (sp_album *p1))
    DEFINE_METHOD1(void, sp_album_add_ref, (sp_album *p1))
    DEFINE_METHOD1(void, sp_album_release, (sp_album *p1))
    DEFINE_METHOD1(const char *, sp_artist_name, (sp_artist *p1))
    DEFINE_METHOD1(bool, sp_artist_is_loaded, (sp_artist *p1))
    DEFINE_METHOD1(const byte *, sp_artist_portrait, (sp_artist *p1))
    DEFINE_METHOD1(void, sp_artist_add_ref, (sp_artist *p1))
    DEFINE_METHOD1(void, sp_artist_release, (sp_artist *p1))
    DEFINE_METHOD4(sp_albumbrowse *, sp_albumbrowse_create, (sp_session *p1, sp_album *p2, albumbrowse_complete_cb *p3, void *p4))
    DEFINE_METHOD1(bool, sp_albumbrowse_is_loaded, (sp_albumbrowse *p1))
    DEFINE_METHOD1(sp_error, sp_albumbrowse_error, (sp_albumbrowse *p1))
    DEFINE_METHOD1(sp_album *, sp_albumbrowse_album, (sp_albumbrowse *p1))
    DEFINE_METHOD1(sp_artist *, sp_albumbrowse_artist, (sp_albumbrowse *p1))
    DEFINE_METHOD1(int, sp_albumbrowse_num_copyrights, (sp_albumbrowse *p1))
    DEFINE_METHOD2(const char *, sp_albumbrowse_copyright, (sp_albumbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_albumbrowse_num_tracks, (sp_albumbrowse *p1))
    DEFINE_METHOD2(sp_track *, sp_albumbrowse_track, (sp_albumbrowse *p1, int p2))
    DEFINE_METHOD1(const char *, sp_albumbrowse_review, (sp_albumbrowse *p1))
    DEFINE_METHOD1(int, sp_albumbrowse_backend_request_duration, (sp_albumbrowse *p1))
    DEFINE_METHOD1(void, sp_albumbrowse_add_ref, (sp_albumbrowse *p1))
    DEFINE_METHOD1(void, sp_albumbrowse_release, (sp_albumbrowse *p1))
    DEFINE_METHOD5(sp_artistbrowse *, sp_artistbrowse_create, (sp_session *p1, sp_artist *p2, sp_artistbrowse_type p3, artistbrowse_complete_cb *p4, void *p5))
    DEFINE_METHOD1(bool, sp_artistbrowse_is_loaded, (sp_artistbrowse *p1))
    DEFINE_METHOD1(sp_error, sp_artistbrowse_error, (sp_artistbrowse *p1))
    DEFINE_METHOD1(sp_artist *, sp_artistbrowse_artist, (sp_artistbrowse *p1))
    DEFINE_METHOD1(int, sp_artistbrowse_num_portraits, (sp_artistbrowse *p1))
    DEFINE_METHOD2(const byte *, sp_artistbrowse_portrait, (sp_artistbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_artistbrowse_num_tracks, (sp_artistbrowse *p1))
    DEFINE_METHOD2(sp_track *, sp_artistbrowse_track, (sp_artistbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_artistbrowse_num_albums, (sp_artistbrowse *p1))
    DEFINE_METHOD2(sp_album *, sp_artistbrowse_album, (sp_artistbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_artistbrowse_num_similar_artists, (sp_artistbrowse *p1))
    DEFINE_METHOD2(sp_artist *, sp_artistbrowse_similar_artist, (sp_artistbrowse *p1, int p2))
    DEFINE_METHOD1(const char *, sp_artistbrowse_biography, (sp_artistbrowse *p1))
    DEFINE_METHOD1(int, sp_artistbrowse_backend_request_duration, (sp_artistbrowse *p1))
    DEFINE_METHOD1(void, sp_artistbrowse_add_ref, (sp_artistbrowse *p1))
    DEFINE_METHOD1(void, sp_artistbrowse_release, (sp_artistbrowse *p1))
    DEFINE_METHOD2(sp_image *, sp_image_create, (sp_session *p1, const byte p2[20]))
    DEFINE_METHOD2(sp_image *, sp_image_create_from_link, (sp_session *p1, sp_link *p2))
    DEFINE_METHOD3(void, sp_image_add_load_callback, (sp_image *p1, image_loaded_cb *p2, void *p3))
    DEFINE_METHOD3(void, sp_image_remove_load_callback, (sp_image *p1, image_loaded_cb *p2, void *p3))
    DEFINE_METHOD1(bool, sp_image_is_loaded, (sp_image *p1))
    DEFINE_METHOD1(sp_error, sp_image_error, (sp_image *p1))
    DEFINE_METHOD1(sp_imageformat, sp_image_format, (sp_image *p1))
    DEFINE_METHOD2(const void *, sp_image_data, (sp_image *p1, size_t *p2))
    DEFINE_METHOD1(const byte *, sp_image_image_id, (sp_image *p1))
    DEFINE_METHOD1(void, sp_image_add_ref, (sp_image *p1))
    DEFINE_METHOD1(void, sp_image_release, (sp_image *p1))
    DEFINE_METHOD10(sp_search *, sp_search_create, (sp_session *p1, const char *p2, int p3, int p4, int p5, int p6, int p7, int p8, search_complete_cb *p9, void *p10))
    DEFINE_METHOD6(sp_search *, sp_radio_search_create, (sp_session *p1, unsigned int p2, unsigned int p3, sp_radio_genre p4, search_complete_cb *p5, void *p6))
    DEFINE_METHOD1(bool, sp_search_is_loaded, (sp_search *p1))
    DEFINE_METHOD1(sp_error, sp_search_error, (sp_search *p1))
    DEFINE_METHOD1(int, sp_search_num_tracks, (sp_search *p1))
    DEFINE_METHOD2(sp_track *, sp_search_track, (sp_search *p1, int p2))
    DEFINE_METHOD1(int, sp_search_num_albums, (sp_search *p1))
    DEFINE_METHOD2(sp_album *, sp_search_album, (sp_search *p1, int p2))
    DEFINE_METHOD1(int, sp_search_num_artists, (sp_search *p1))
    DEFINE_METHOD2(sp_artist *, sp_search_artist, (sp_search *p1, int p2))
    DEFINE_METHOD1(const char *, sp_search_query, (sp_search *p1))
    DEFINE_METHOD1(const char *, sp_search_did_you_mean, (sp_search *p1))
    DEFINE_METHOD1(int, sp_search_total_tracks, (sp_search *p1))
    DEFINE_METHOD1(int, sp_search_total_albums, (sp_search *p1))
    DEFINE_METHOD1(int, sp_search_total_artists, (sp_search *p1))
    DEFINE_METHOD1(void, sp_search_add_ref, (sp_search *p1))
    DEFINE_METHOD1(void, sp_search_release, (sp_search *p1))
    DEFINE_METHOD1(bool, sp_playlist_is_loaded, (sp_playlist *p1))
    DEFINE_METHOD3(void, sp_playlist_add_callbacks, (sp_playlist *p1, sp_playlist_callbacks *p2, void *p3))
    DEFINE_METHOD3(void, sp_playlist_remove_callbacks, (sp_playlist *p1, sp_playlist_callbacks *p2, void *p3))
    DEFINE_METHOD1(int, sp_playlist_num_tracks, (sp_playlist *p1))
    DEFINE_METHOD2(sp_track *, sp_playlist_track, (sp_playlist *p1, int p2))
    DEFINE_METHOD2(int, sp_playlist_track_create_time, (sp_playlist *p1, int p2))
    DEFINE_METHOD2(sp_user *, sp_playlist_track_creator, (sp_playlist *p1, int p2))
    DEFINE_METHOD2(bool, sp_playlist_track_seen, (sp_playlist *p1, int p2))
    DEFINE_METHOD3(sp_error, sp_playlist_track_set_seen, (sp_playlist *p1, int p2, bool p3))
    DEFINE_METHOD2(const char *, sp_playlist_track_message, (sp_playlist *p1, int p2))
    DEFINE_METHOD1(const char *, sp_playlist_name, (sp_playlist *p1))
    DEFINE_METHOD2(sp_error, sp_playlist_rename, (sp_playlist *p1, const char *p2))
    DEFINE_METHOD1(sp_user *, sp_playlist_owner, (sp_playlist *p1))
    DEFINE_METHOD1(bool, sp_playlist_is_collaborative, (sp_playlist *p1))
    DEFINE_METHOD2(void, sp_playlist_set_collaborative, (sp_playlist *p1, bool p2))
    DEFINE_METHOD2(void, sp_playlist_set_autolink_tracks, (sp_playlist *p1, bool p2))
    DEFINE_METHOD1(const char *, sp_playlist_get_description, (sp_playlist *p1))
    DEFINE_METHOD2(bool, sp_playlist_get_image, (sp_playlist *p1, byte p2[20]))
    DEFINE_METHOD1(bool, sp_playlist_has_pending_changes, (sp_playlist *p1))
    DEFINE_METHOD5(sp_error, sp_playlist_add_tracks, (sp_playlist *p1, sp_track *const*p2, int p3, int p4, sp_session *p5))
    DEFINE_METHOD3(sp_error, sp_playlist_remove_tracks, (sp_playlist *p1, const int *p2, int p3))
    DEFINE_METHOD4(sp_error, sp_playlist_reorder_tracks, (sp_playlist *p1, const int *p2, int p3, int p4))
    DEFINE_METHOD1(unsigned int, sp_playlist_num_subscribers, (sp_playlist *p1))
    DEFINE_METHOD1(sp_subscribers *, sp_playlist_subscribers, (sp_playlist *p1))
    DEFINE_METHOD1(void, sp_playlist_subscribers_free, (sp_subscribers *p1))
    DEFINE_METHOD2(void, sp_playlist_update_subscribers, (sp_session *p1, sp_playlist *p2))
    DEFINE_METHOD2(bool, sp_playlist_is_in_ram, (sp_session *p1, sp_playlist *p2))
    DEFINE_METHOD3(void, sp_playlist_set_in_ram, (sp_session *p1, sp_playlist *p2, bool p3))
    DEFINE_METHOD2(sp_playlist *, sp_playlist_create, (sp_session *p1, sp_link *p2))
    DEFINE_METHOD3(void, sp_playlist_set_offline_mode, (sp_session *p1, sp_playlist *p2, bool p3))
    DEFINE_METHOD2(sp_playlist_offline_status, sp_playlist_get_offline_status, (sp_session *p1, sp_playlist *p2))
    DEFINE_METHOD2(int, sp_playlist_get_offline_download_completed, (sp_session *p1, sp_playlist *p2))
    DEFINE_METHOD1(void, sp_playlist_add_ref, (sp_playlist *p1))
    DEFINE_METHOD1(void, sp_playlist_release, (sp_playlist *p1))
    DEFINE_METHOD3(void, sp_playlistcontainer_add_callbacks, (sp_playlistcontainer *p1, sp_playlistcontainer_callbacks *p2, void *p3))
    DEFINE_METHOD3(void, sp_playlistcontainer_remove_callbacks, (sp_playlistcontainer *p1, sp_playlistcontainer_callbacks *p2, void *p3))
    DEFINE_METHOD1(int, sp_playlistcontainer_num_playlists, (sp_playlistcontainer *p1))
    DEFINE_METHOD1(bool, sp_playlistcontainer_is_loaded, (sp_playlistcontainer *p1))
    DEFINE_METHOD2(sp_playlist *, sp_playlistcontainer_playlist, (sp_playlistcontainer *p1, int p2))
    DEFINE_METHOD2(sp_playlist_type, sp_playlistcontainer_playlist_type, (sp_playlistcontainer *p1, int p2))
    DEFINE_METHOD4(sp_error, sp_playlistcontainer_playlist_folder_name, (sp_playlistcontainer *p1, int p2, char *p3, int p4))
    DEFINE_METHOD2(sp_uint64, sp_playlistcontainer_playlist_folder_id, (sp_playlistcontainer *p1, int p2))
    DEFINE_METHOD2(sp_playlist *, sp_playlistcontainer_add_new_playlist, (sp_playlistcontainer *p1, const char *p2))
    DEFINE_METHOD2(sp_playlist *, sp_playlistcontainer_add_playlist, (sp_playlistcontainer *p1, sp_link *p2))
    DEFINE_METHOD2(sp_error, sp_playlistcontainer_remove_playlist, (sp_playlistcontainer *p1, int p2))
    DEFINE_METHOD4(sp_error, sp_playlistcontainer_move_playlist, (sp_playlistcontainer *p1, int p2, int p3, bool p4))
    DEFINE_METHOD3(sp_error, sp_playlistcontainer_add_folder, (sp_playlistcontainer *p1, int p2, const char *p3))
    DEFINE_METHOD1(sp_user *, sp_playlistcontainer_owner, (sp_playlistcontainer *p1))
    DEFINE_METHOD1(void, sp_playlistcontainer_add_ref, (sp_playlistcontainer *p1))
    DEFINE_METHOD1(void, sp_playlistcontainer_release, (sp_playlistcontainer *p1))
    DEFINE_METHOD1(const char *, sp_user_canonical_name, (sp_user *p1))
    DEFINE_METHOD1(const char *, sp_user_display_name, (sp_user *p1))
    DEFINE_METHOD1(bool, sp_user_is_loaded, (sp_user *p1))
    DEFINE_METHOD1(void, sp_user_add_ref, (sp_user *p1))
    DEFINE_METHOD1(void, sp_user_release, (sp_user *p1))
    DEFINE_METHOD6(sp_toplistbrowse *, sp_toplistbrowse_create, (sp_session *p1, sp_toplisttype p2, sp_toplistregion p3, const char *p4, toplistbrowse_complete_cb *p5, void *p6))
    DEFINE_METHOD1(bool, sp_toplistbrowse_is_loaded, (sp_toplistbrowse *p1))
    DEFINE_METHOD1(sp_error, sp_toplistbrowse_error, (sp_toplistbrowse *p1))
    DEFINE_METHOD1(void, sp_toplistbrowse_add_ref, (sp_toplistbrowse *p1))
    DEFINE_METHOD1(void, sp_toplistbrowse_release, (sp_toplistbrowse *p1))
    DEFINE_METHOD1(int, sp_toplistbrowse_num_artists, (sp_toplistbrowse *p1))
    DEFINE_METHOD2(sp_artist *, sp_toplistbrowse_artist, (sp_toplistbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_toplistbrowse_num_albums, (sp_toplistbrowse *p1))
    DEFINE_METHOD2(sp_album *, sp_toplistbrowse_album, (sp_toplistbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_toplistbrowse_num_tracks, (sp_toplistbrowse *p1))
    DEFINE_METHOD2(sp_track *, sp_toplistbrowse_track, (sp_toplistbrowse *p1, int p2))
    DEFINE_METHOD1(int, sp_toplistbrowse_backend_request_duration, (sp_toplistbrowse *p1))
    DEFINE_METHOD7(sp_inbox *, sp_inbox_post_tracks, (sp_session *p1, const char *p2, sp_track * const *p3, int p4, const char *p5, inboxpost_complete_cb *p6, void *p7))
    DEFINE_METHOD1(sp_error, sp_inbox_error, (sp_inbox *p1))
    DEFINE_METHOD1(void, sp_inbox_add_ref, (sp_inbox *p1))
    DEFINE_METHOD1(void, sp_inbox_release, (sp_inbox *p1))
    DEFINE_METHOD0(const char *, sp_build_id)

    BEGIN_METHOD_RESOLVE()
    RESOLVE_METHOD(sp_error_message)
    RESOLVE_METHOD(sp_session_create)
    RESOLVE_METHOD(sp_session_release)
    RESOLVE_METHOD(sp_session_login)
    RESOLVE_METHOD(sp_session_relogin)
    RESOLVE_METHOD(sp_session_remembered_user)
    RESOLVE_METHOD(sp_session_forget_me)
    RESOLVE_METHOD(sp_session_user)
    RESOLVE_METHOD(sp_session_logout)
    RESOLVE_METHOD(sp_session_connectionstate)
    RESOLVE_METHOD(sp_session_userdata)
    RESOLVE_METHOD(sp_session_set_cache_size)
    RESOLVE_METHOD(sp_session_process_events)
    RESOLVE_METHOD(sp_session_player_load)
    RESOLVE_METHOD(sp_session_player_seek)
    RESOLVE_METHOD(sp_session_player_play)
    RESOLVE_METHOD(sp_session_player_unload)
    RESOLVE_METHOD(sp_session_player_prefetch)
    RESOLVE_METHOD(sp_session_playlistcontainer)
    RESOLVE_METHOD(sp_session_inbox_create)
    RESOLVE_METHOD(sp_session_starred_create)
    RESOLVE_METHOD(sp_session_starred_for_user_create)
    RESOLVE_METHOD(sp_session_publishedcontainer_for_user_create)
    RESOLVE_METHOD(sp_session_preferred_bitrate)
    RESOLVE_METHOD(sp_session_preferred_offline_bitrate)
    RESOLVE_METHOD(sp_session_get_volume_normalization)
    RESOLVE_METHOD(sp_session_set_volume_normalization)
    RESOLVE_METHOD(sp_session_set_connection_type)
    RESOLVE_METHOD(sp_session_set_connection_rules)
    RESOLVE_METHOD(sp_offline_tracks_to_sync)
    RESOLVE_METHOD(sp_offline_num_playlists)
    RESOLVE_METHOD(sp_offline_sync_get_status)
    RESOLVE_METHOD(sp_offline_time_left)
    RESOLVE_METHOD(sp_session_user_country)
    RESOLVE_METHOD(sp_link_create_from_string)
    RESOLVE_METHOD(sp_link_create_from_track)
    RESOLVE_METHOD(sp_link_create_from_album)
    RESOLVE_METHOD(sp_link_create_from_album_cover)
    RESOLVE_METHOD(sp_link_create_from_artist)
    RESOLVE_METHOD(sp_link_create_from_artist_portrait)
    RESOLVE_METHOD(sp_link_create_from_artistbrowse_portrait)
    RESOLVE_METHOD(sp_link_create_from_search)
    RESOLVE_METHOD(sp_link_create_from_playlist)
    RESOLVE_METHOD(sp_link_create_from_user)
    RESOLVE_METHOD(sp_link_create_from_image)
    RESOLVE_METHOD(sp_link_as_string)
    RESOLVE_METHOD(sp_link_type)
    RESOLVE_METHOD(sp_link_as_track)
    RESOLVE_METHOD(sp_link_as_track_and_offset)
    RESOLVE_METHOD(sp_link_as_album)
    RESOLVE_METHOD(sp_link_as_artist)
    RESOLVE_METHOD(sp_link_as_user)
    RESOLVE_METHOD(sp_link_add_ref)
    RESOLVE_METHOD(sp_link_release)
    RESOLVE_METHOD(sp_track_is_loaded)
    RESOLVE_METHOD(sp_track_error)
    RESOLVE_METHOD(sp_track_offline_get_status)
    RESOLVE_METHOD(sp_track_get_availability)
    RESOLVE_METHOD(sp_track_is_local)
    RESOLVE_METHOD(sp_track_is_autolinked)
    RESOLVE_METHOD(sp_track_is_placeholder)
    RESOLVE_METHOD(sp_track_is_starred)
    RESOLVE_METHOD(sp_track_set_starred)
    RESOLVE_METHOD(sp_track_num_artists)
    RESOLVE_METHOD(sp_track_artist)
    RESOLVE_METHOD(sp_track_album)
    RESOLVE_METHOD(sp_track_name)
    RESOLVE_METHOD(sp_track_duration)
    RESOLVE_METHOD(sp_track_popularity)
    RESOLVE_METHOD(sp_track_disc)
    RESOLVE_METHOD(sp_track_index)
    RESOLVE_METHOD(sp_localtrack_create)
    RESOLVE_METHOD(sp_track_add_ref)
    RESOLVE_METHOD(sp_track_release)
    RESOLVE_METHOD(sp_album_is_loaded)
    RESOLVE_METHOD(sp_album_is_available)
    RESOLVE_METHOD(sp_album_artist)
    RESOLVE_METHOD(sp_album_cover)
    RESOLVE_METHOD(sp_album_name)
    RESOLVE_METHOD(sp_album_year)
    RESOLVE_METHOD(sp_album_type)
    RESOLVE_METHOD(sp_album_add_ref)
    RESOLVE_METHOD(sp_album_release)
    RESOLVE_METHOD(sp_artist_name)
    RESOLVE_METHOD(sp_artist_is_loaded)
    RESOLVE_METHOD(sp_artist_portrait)
    RESOLVE_METHOD(sp_artist_add_ref)
    RESOLVE_METHOD(sp_artist_release)
    RESOLVE_METHOD(sp_albumbrowse_create)
    RESOLVE_METHOD(sp_albumbrowse_is_loaded)
    RESOLVE_METHOD(sp_albumbrowse_error)
    RESOLVE_METHOD(sp_albumbrowse_album)
    RESOLVE_METHOD(sp_albumbrowse_artist)
    RESOLVE_METHOD(sp_albumbrowse_num_copyrights)
    RESOLVE_METHOD(sp_albumbrowse_copyright)
    RESOLVE_METHOD(sp_albumbrowse_num_tracks)
    RESOLVE_METHOD(sp_albumbrowse_track)
    RESOLVE_METHOD(sp_albumbrowse_review)
    RESOLVE_METHOD(sp_albumbrowse_backend_request_duration)
    RESOLVE_METHOD(sp_albumbrowse_add_ref)
    RESOLVE_METHOD(sp_albumbrowse_release)
    RESOLVE_METHOD(sp_artistbrowse_create)
    RESOLVE_METHOD(sp_artistbrowse_is_loaded)
    RESOLVE_METHOD(sp_artistbrowse_error)
    RESOLVE_METHOD(sp_artistbrowse_artist)
    RESOLVE_METHOD(sp_artistbrowse_num_portraits)
    RESOLVE_METHOD(sp_artistbrowse_portrait)
    RESOLVE_METHOD(sp_artistbrowse_num_tracks)
    RESOLVE_METHOD(sp_artistbrowse_track)
    RESOLVE_METHOD(sp_artistbrowse_num_albums)
    RESOLVE_METHOD(sp_artistbrowse_album)
    RESOLVE_METHOD(sp_artistbrowse_num_similar_artists)
    RESOLVE_METHOD(sp_artistbrowse_similar_artist)
    RESOLVE_METHOD(sp_artistbrowse_biography)
    RESOLVE_METHOD(sp_artistbrowse_backend_request_duration)
    RESOLVE_METHOD(sp_artistbrowse_add_ref)
    RESOLVE_METHOD(sp_artistbrowse_release)
    RESOLVE_METHOD(sp_image_create)
    RESOLVE_METHOD(sp_image_create_from_link)
    RESOLVE_METHOD(sp_image_add_load_callback)
    RESOLVE_METHOD(sp_image_remove_load_callback)
    RESOLVE_METHOD(sp_image_is_loaded)
    RESOLVE_METHOD(sp_image_error)
    RESOLVE_METHOD(sp_image_format)
    RESOLVE_METHOD(sp_image_data)
    RESOLVE_METHOD(sp_image_image_id)
    RESOLVE_METHOD(sp_image_add_ref)
    RESOLVE_METHOD(sp_image_release)
    RESOLVE_METHOD(sp_search_create)
    RESOLVE_METHOD(sp_radio_search_create)
    RESOLVE_METHOD(sp_search_is_loaded)
    RESOLVE_METHOD(sp_search_error)
    RESOLVE_METHOD(sp_search_num_tracks)
    RESOLVE_METHOD(sp_search_track)
    RESOLVE_METHOD(sp_search_num_albums)
    RESOLVE_METHOD(sp_search_album)
    RESOLVE_METHOD(sp_search_num_artists)
    RESOLVE_METHOD(sp_search_artist)
    RESOLVE_METHOD(sp_search_query)
    RESOLVE_METHOD(sp_search_did_you_mean)
    RESOLVE_METHOD(sp_search_total_tracks)
    RESOLVE_METHOD(sp_search_total_albums)
    RESOLVE_METHOD(sp_search_total_artists)
    RESOLVE_METHOD(sp_search_add_ref)
    RESOLVE_METHOD(sp_search_release)
    RESOLVE_METHOD(sp_playlist_is_loaded)
    RESOLVE_METHOD(sp_playlist_add_callbacks)
    RESOLVE_METHOD(sp_playlist_remove_callbacks)
    RESOLVE_METHOD(sp_playlist_num_tracks)
    RESOLVE_METHOD(sp_playlist_track)
    RESOLVE_METHOD(sp_playlist_track_create_time)
    RESOLVE_METHOD(sp_playlist_track_creator)
    RESOLVE_METHOD(sp_playlist_track_seen)
    RESOLVE_METHOD(sp_playlist_track_set_seen)
    RESOLVE_METHOD(sp_playlist_track_message)
    RESOLVE_METHOD(sp_playlist_name)
    RESOLVE_METHOD(sp_playlist_rename)
    RESOLVE_METHOD(sp_playlist_owner)
    RESOLVE_METHOD(sp_playlist_is_collaborative)
    RESOLVE_METHOD(sp_playlist_set_collaborative)
    RESOLVE_METHOD(sp_playlist_set_autolink_tracks)
    RESOLVE_METHOD(sp_playlist_get_description)
    RESOLVE_METHOD(sp_playlist_get_image)
    RESOLVE_METHOD(sp_playlist_has_pending_changes)
    RESOLVE_METHOD(sp_playlist_add_tracks)
    RESOLVE_METHOD(sp_playlist_remove_tracks)
    RESOLVE_METHOD(sp_playlist_reorder_tracks)
    RESOLVE_METHOD(sp_playlist_num_subscribers)
    RESOLVE_METHOD(sp_playlist_subscribers)
    RESOLVE_METHOD(sp_playlist_subscribers_free)
    RESOLVE_METHOD(sp_playlist_update_subscribers)
    RESOLVE_METHOD(sp_playlist_is_in_ram)
    RESOLVE_METHOD(sp_playlist_set_in_ram)
    RESOLVE_METHOD(sp_playlist_create)
    RESOLVE_METHOD(sp_playlist_set_offline_mode)
    RESOLVE_METHOD(sp_playlist_get_offline_status)
    RESOLVE_METHOD(sp_playlist_get_offline_download_completed)
    RESOLVE_METHOD(sp_playlist_add_ref)
    RESOLVE_METHOD(sp_playlist_release)
    RESOLVE_METHOD(sp_playlistcontainer_add_callbacks)
    RESOLVE_METHOD(sp_playlistcontainer_remove_callbacks)
    RESOLVE_METHOD(sp_playlistcontainer_num_playlists)
    RESOLVE_METHOD(sp_playlistcontainer_is_loaded)
    RESOLVE_METHOD(sp_playlistcontainer_playlist)
    RESOLVE_METHOD(sp_playlistcontainer_playlist_type)
    RESOLVE_METHOD(sp_playlistcontainer_playlist_folder_name)
    RESOLVE_METHOD(sp_playlistcontainer_playlist_folder_id)
    RESOLVE_METHOD(sp_playlistcontainer_add_new_playlist)
    RESOLVE_METHOD(sp_playlistcontainer_add_playlist)
    RESOLVE_METHOD(sp_playlistcontainer_remove_playlist)
    RESOLVE_METHOD(sp_playlistcontainer_move_playlist)
    RESOLVE_METHOD(sp_playlistcontainer_add_folder)
    RESOLVE_METHOD(sp_playlistcontainer_owner)
    RESOLVE_METHOD(sp_playlistcontainer_add_ref)
    RESOLVE_METHOD(sp_playlistcontainer_release)
    RESOLVE_METHOD(sp_user_canonical_name)
    RESOLVE_METHOD(sp_user_display_name)
    RESOLVE_METHOD(sp_user_is_loaded)
    RESOLVE_METHOD(sp_user_add_ref)
    RESOLVE_METHOD(sp_user_release)
    RESOLVE_METHOD(sp_toplistbrowse_create)
    RESOLVE_METHOD(sp_toplistbrowse_is_loaded)
    RESOLVE_METHOD(sp_toplistbrowse_error)
    RESOLVE_METHOD(sp_toplistbrowse_add_ref)
    RESOLVE_METHOD(sp_toplistbrowse_release)
    RESOLVE_METHOD(sp_toplistbrowse_num_artists)
    RESOLVE_METHOD(sp_toplistbrowse_artist)
    RESOLVE_METHOD(sp_toplistbrowse_num_albums)
    RESOLVE_METHOD(sp_toplistbrowse_album)
    RESOLVE_METHOD(sp_toplistbrowse_num_tracks)
    RESOLVE_METHOD(sp_toplistbrowse_track)
    RESOLVE_METHOD(sp_toplistbrowse_backend_request_duration)
    RESOLVE_METHOD(sp_inbox_post_tracks)
    RESOLVE_METHOD(sp_inbox_error)
    RESOLVE_METHOD(sp_inbox_add_ref)
    RESOLVE_METHOD(sp_inbox_release)
    RESOLVE_METHOD(sp_build_id)
    END_METHOD_RESOLVE()
};
