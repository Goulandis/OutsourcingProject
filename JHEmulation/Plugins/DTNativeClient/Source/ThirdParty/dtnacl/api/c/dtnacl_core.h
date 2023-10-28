#pragma once

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
	#define DTNACL_EXPORT		__declspec(dllexport)
	#define DTNACL_IMPORT		__declspec(dllimport)
	#define DTNACL_INLINE		__forceinline
	#define DTNACL_RESTRICT		__restrict
#else
	#define DTNACL_EXPORT		__attribute__((visibility("default")))
	#define DTNACL_IMPORT
	#define DTNACL_INLINE		__inline__
	#define DTNACL_RESTRICT		__restrict
#endif

#if defined(DTNACL_SHARED_LIBRARY)
	#define DTNACL_API			DTNACL_EXPORT
#else
	#define DTNACL_API			DTNACL_IMPORT
#endif

#ifndef DTNACL_NULL_HANDLE
	#define DTNACL_NULL_HANDLE nullptr
#endif

#define DTNACL_DEFINE_HANDLE(object) typedef struct object##_t* object;

/*
 */
#define DTNACL_CORE_OS_ANDROID			"Android"
#define DTNACL_CORE_OS_IOS				"IOS"
#define DTNACL_CORE_OS_WINDOWS			"Windows"
#define DTNACL_CORE_OS_MAC				"Mac"
#define DTNACL_CORE_OS_WEB				"Web"
#define DTNACL_CORE_OS_LINUX			"Linux"
#define DTNACL_CORE_OS_UNKNOWN			"Unknown"

#define DTNACL_CORE_ENGINE_SPACE		"SpaceEngine"
#define DTNACL_CORE_ENGINE_FLEX			"FlexEngine"
#define DTNACL_CORE_ENGINE_TWINGINE		"Twingine"
#define DTNACL_CORE_ENGINE_UNITY		"Unity"
#define DTNACL_CORE_ENGINE_UNREAL		"UnrealEngine"
#define DTNACL_CORE_ENGINE_UNIGINE		"Unigine"
#define DTNACL_CORE_ENGINE_FUI			"FUI"
#define DTNACL_CORE_ENGINE_API			"API"
#define DTNACL_CORE_ENGINE_UNKNOWN		"Unknown"

#define DTNACL_CORE_REQUEST_CREATE		"create"
#define DTNACL_CORE_REQUEST_GET			"get"
#define DTNACL_CORE_REQUEST_PATCH		"patch"
#define DTNACL_CORE_REQUEST_REMOVE		"remove"
#define DTNACL_CORE_REQUEST_FIND		"find"

#define DTNACL_CORE_CONNECTION_SETTINGS_PING_INTERVAL_DEFAULT 0
#define DTNACL_CORE_CONNECTION_SETTINGS_PING_TIMEOUT_DEFAULT 0
#define DTNACL_CORE_CONNECTION_SETTINGS_RECONNECT_DELAY_DEFAULT 5000
#define DTNACL_CORE_CONNECTION_SETTINGS_RECONNECT_DELAY_MAX_DEFAULT 25000
#define DTNACL_CORE_CONNECTION_SETTINGS_RECONNECT_ATTEMPTS_DEFAULT 3

#define DTNACL_CORE_HTTP_SETTINGS_UPLOAD_CHUNK_ATTEMPTS_DEFAULT 5
#define DTNACL_CORE_HTTP_SETTINGS_UPLOAD_CHUNK_SIZE_DEFAULT (1024 * 1024)

/*
 */
DTNACL_DEFINE_HANDLE(DTNACL_Core_Session)
DTNACL_DEFINE_HANDLE(DTNACL_Core_TransportData)
DTNACL_DEFINE_HANDLE(DTNACL_Core_TransportDataIterator)
DTNACL_DEFINE_HANDLE(DTNACL_Core_TransportDataPool)

/*
 */
typedef uint64_t DTNACL_Core_DateTime;

typedef struct DTNACL_Core_UUID_t
{
	union uint128
	{
		uint64_t as_long[2];
		uint8_t as_char[16];
	} value;
	uint32_t bytes;
} DTNACL_Core_UUID;

typedef struct DTNACL_Core_User_t
{
	DTNACL_Core_UUID id;
	DTNACL_Core_UUID world_id;
	DTNACL_Core_UUID enterprise_id;
	DTNACL_Core_UUID tenant_id;
	const char *access_token;
} DTNACL_Core_User;

typedef struct DTNACL_Core_AuthData_t
{
	const char *login;
	const char *password;
	const char *client_engine;
	const char *client_os;
} DTNACL_Core_AuthData;

typedef struct DTNACL_Core_ConnectionSettings_t
{
	uint32_t reconnect_attempts;
	uint32_t reconnect_delay;
	uint32_t reconnect_delay_max;
	uint32_t ping_interval;
	uint32_t ping_timeout;
} DTNACL_Core_ConnectionSettings;

typedef struct DTNACL_Core_HttpSettings_t
{
	uint32_t upload_chunk_size;
	uint32_t upload_chunk_attempts;
} DTNACL_Core_HttpSettings;

/*
 */
typedef enum DTNACL_Core_LogLevel_t
{
	DTNACL_CORE_LOG_LEVEL_NONE = 0x0000,
	DTNACL_CORE_LOG_LEVEL_MESSAGE = 0x0001,
	DTNACL_CORE_LOG_LEVEL_WARNING = 0x0002,
	DTNACL_CORE_LOG_LEVEL_ERROR = 0x0004,
	DTNACL_CORE_LOG_LEVEL_FATAL = 0x0008,
	DTNACL_CORE_LOG_LEVEL_VERBOSE = 0x0010,
	DTNACL_CORE_LOG_LEVEL_ALL = DTNACL_CORE_LOG_LEVEL_MESSAGE | DTNACL_CORE_LOG_LEVEL_WARNING | DTNACL_CORE_LOG_LEVEL_ERROR | DTNACL_CORE_LOG_LEVEL_FATAL | DTNACL_CORE_LOG_LEVEL_VERBOSE,
} DTNACL_Core_LogLevel;

typedef enum DTNACL_Core_Status_t
{
	DTNACL_CORE_STATUS_OK = 200,
	DTNACL_CORE_STATUS_BAD_REQUEST = 400,
	DTNACL_CORE_STATUS_INTERNAL_SERVER_ERROR = 500,
	DTNACL_CORE_STATUS_UNAVAILABLE = 503,
} DTNACL_Core_Status;

typedef enum DTNACL_Core_ConnectionStatus_t
{
	DTNACL_CORE_CONNECTION_STATUS_DISCONNECTED = 0,
	DTNACL_CORE_CONNECTION_STATUS_CONNECTED,
	DTNACL_CORE_CONNECTION_STATUS_FAILED,
	DTNACL_CORE_CONNECTION_STATUS_RECONNECT_STARTED,
	DTNACL_CORE_CONNECTION_STATUS_RECONNECT_ATTEMPT,
} DTNACL_Core_ConnectionStatus;

typedef enum DTNACL_Core_TransportDataType_t
{
	DTNACL_CORE_TRANSPORT_DATA_TYPE_BOOL = 0,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_INT,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_FLOAT,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_DOUBLE,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_STRING,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_OBJECT,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_ARRAY,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_NULL_TYPE,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_BINARY,
	DTNACL_CORE_TRANSPORT_DATA_TYPE_UNKNOWN,
} DTNACL_Core_TransportDataType;

/*
 */
typedef void(*DTNACL_Core_ConnectionCallback)(DTNACL_Core_Session session, DTNACL_Core_ConnectionStatus connection_status, void *user_data);
typedef void(*DTNACL_Core_EventCallback)(DTNACL_Core_Session session, const DTNACL_Core_TransportData *responses, uint64_t num_responses, const char *event_name, void *user_data);
typedef void(*DTNACL_Core_RequestCallback)(DTNACL_Core_Session session, const DTNACL_Core_TransportData *responses, uint64_t num_responses, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Core_DownloadCallback)(DTNACL_Core_Session session, const uint8_t *data, uint64_t size, DTNACL_Core_Status status, void *user_data);
typedef void(*DTNACL_Core_UploadCallback)(DTNACL_Core_Session session, DTNACL_Core_Status status, void *user_data);

typedef void(*DTNACL_Core_LogCallback)(const char *format, ...);

/*
 */
DTNACL_API void dtnaclCoreSetLogCallback(DTNACL_Core_LogCallback callback, int level = DTNACL_CORE_LOG_LEVEL_ALL);

/* Session
 */
DTNACL_API DTNACL_Core_Session dtnaclCoreSessionCreate(const char *certificate_file = nullptr, const char *certificate_directory = nullptr);
DTNACL_API void dtnaclCoreSessionDestroy(DTNACL_Core_Session session);
DTNACL_API bool dtnaclCoreSessionIsIdle(DTNACL_Core_Session session);
DTNACL_API void dtnaclCoreSessionUpdate(DTNACL_Core_Session session);
DTNACL_API void dtnaclCoreSessionClear(DTNACL_Core_Session session);

DTNACL_API void dtnaclCoreSessionWebsocketSetConnectionSettings(DTNACL_Core_Session session, const DTNACL_Core_ConnectionSettings *settings);
DTNACL_API const DTNACL_Core_ConnectionSettings *dtnaclCoreSessionWebsocketGetConnectionSettings(DTNACL_Core_Session session);

DTNACL_API void dtnaclCoreSessionWebsocketConnect(DTNACL_Core_Session session, const char *url, DTNACL_Core_ConnectionCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclCoreSessionWebsocketAuthenticate(DTNACL_Core_Session session, DTNACL_Core_TransportData data, DTNACL_Core_RequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclCoreSessionWebsocketAuthenticateLocal(DTNACL_Core_Session session, const DTNACL_Core_AuthData *data, DTNACL_Core_RequestCallback callback, void *user_data = nullptr);
DTNACL_API bool dtnaclCoreSessionWebsocketIsConnected(DTNACL_Core_Session session);
DTNACL_API DTNACL_Core_ConnectionStatus dtnaclCoreSessionWebsocketGetConnectionStatus(DTNACL_Core_Session session);
DTNACL_API void dtnaclCoreSessionWebsocketDisconnect(DTNACL_Core_Session session);

DTNACL_API const DTNACL_Core_User *dtnaclCoreSessionWebsocketGetUser(DTNACL_Core_Session session);

DTNACL_API void dtnaclCoreSessionWebsocketAddEventListener(DTNACL_Core_Session session, const char *event_name, DTNACL_Core_EventCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclCoreSessionWebsocketRemoveEventListener(DTNACL_Core_Session session, const char *event_name);
DTNACL_API void dtnaclCoreSessionClearWebsocketEventListeners(DTNACL_Core_Session session);

DTNACL_API void dtnaclCoreSessionWebsocketSend(DTNACL_Core_Session session, const char *method_name, const char *service_name, const DTNACL_Core_TransportData *parameters, uint64_t num_parameters, DTNACL_Core_RequestCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclCoreSessionClearWebsocketRequests(DTNACL_Core_Session session);

DTNACL_API void dtnaclCoreSessionHttpSetSettings(DTNACL_Core_Session session, const DTNACL_Core_HttpSettings *settings);
DTNACL_API const DTNACL_Core_HttpSettings *dtnaclCoreSessionHttpGetSettings(DTNACL_Core_Session session);

DTNACL_API void dtnaclCoreSessionHttpDownload(DTNACL_Core_Session session, const char *url, DTNACL_Core_DownloadCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclCoreSessionHttpUpload(DTNACL_Core_Session session, const char *url, const uint8_t *data, uint64_t size, const char *content_type, DTNACL_Core_UploadCallback callback, void *user_data = nullptr);
DTNACL_API void dtnaclCoreSessionClearHttpRequests(DTNACL_Core_Session session);

/* TransportData
 */
// memory management
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataRetain(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclCoreTransportDataRelease(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// pool
DTNACL_API DTNACL_Core_TransportDataPool dtnaclCoreTransportDataPoolGetDefault();
DTNACL_API DTNACL_Core_TransportDataPool dtnaclCoreTransportDataPoolCreate(uint64_t size = 512);
DTNACL_API void dtnaclCoreTransportDataPoolDestroy(DTNACL_Core_TransportDataPool pool);
DTNACL_API void dtnaclCoreTransportDataPoolClear(DTNACL_Core_TransportDataPool pool);

// creation
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateNull(DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateBool(bool value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateInt(int value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateFloat(float value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateDouble(double value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateString(const char *value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateUUID(const DTNACL_Core_UUID &uuid, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateBinary(const uint8_t *data, uint64_t size, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateObject(DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateArray(DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// getters / setters
DTNACL_API DTNACL_Core_TransportDataType dtnaclCoreTransportDataGetType(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetBoolValue(DTNACL_Core_TransportData data, bool value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataGetBoolValue(DTNACL_Core_TransportData data, bool default_value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetIntValue(DTNACL_Core_TransportData data, int value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API int dtnaclCoreTransportDataGetIntValue(DTNACL_Core_TransportData data, int default_value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetFloatValue(DTNACL_Core_TransportData data, float value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API float dtnaclCoreTransportDataGetFloatValue(DTNACL_Core_TransportData data, float default_value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetDoubleValue(DTNACL_Core_TransportData data, double value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API double dtnaclCoreTransportDataGetDoubleValue(DTNACL_Core_TransportData data, double default_value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetStringValue(DTNACL_Core_TransportData data, const char *value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API const char *dtnaclCoreTransportDataGetStringValue(DTNACL_Core_TransportData data, const char *default_value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetUUIDValue(DTNACL_Core_TransportData data, const DTNACL_Core_UUID &value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_UUID dtnaclCoreTransportDataGetUUIDValue(DTNACL_Core_TransportData data, const DTNACL_Core_UUID &default_value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// object
DTNACL_API bool dtnaclCoreTransportDataHasMember(DTNACL_Core_TransportData data, const char *key, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetObjectMember(DTNACL_Core_TransportData data, const char *key, DTNACL_Core_TransportData value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataGetObjectMember(DTNACL_Core_TransportData data, const char *key, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API uint64_t dtnaclCoreTransportDataGetObjectSize(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataGetObjectMemberByIndex(DTNACL_Core_TransportData data, uint64_t index, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API const char *dtnaclCoreTransportDataGetObjectKeyByIndex(DTNACL_Core_TransportData data, uint64_t index, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// iterator
DTNACL_API DTNACL_Core_TransportDataIterator dtnaclCoreTransportDataCreateIterator(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclCoreTransportDataDestroyIterator(DTNACL_Core_TransportDataIterator iterator, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API const char *dtnaclCoreTransportDataIteratorGetKey(DTNACL_Core_TransportDataIterator iterator, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataIteratorGetValue(DTNACL_Core_TransportDataIterator iterator, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclCoreTransportDataIteratorNext(DTNACL_Core_TransportDataIterator iterator, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataIteratorIsEnd(DTNACL_Core_TransportDataIterator iterator, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// array
DTNACL_API uint64_t dtnaclCoreTransportDataGetArrayItemCount(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataGetArrayItem(DTNACL_Core_TransportData data, uint64_t index, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataSetArrayItem(DTNACL_Core_TransportData data, uint64_t index, DTNACL_Core_TransportData value, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API bool dtnaclCoreTransportDataAddArrayItem(DTNACL_Core_TransportData data, DTNACL_Core_TransportData item, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// binary
DTNACL_API uint64_t dtnaclCoreTransportDataGetBinarySize(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API const uint8_t *dtnaclCoreTransportDataGetBinaryData(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

// json
DTNACL_API const char *dtnaclCoreTransportDataCreateJsonString(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API void dtnaclCoreTransportDataDestroyJsonString(const char *json, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataCreateFromJson(const char *json, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);
DTNACL_API DTNACL_Core_TransportData dtnaclCoreTransportDataDeepCopy(DTNACL_Core_TransportData data, DTNACL_Core_TransportDataPool pool = DTNACL_NULL_HANDLE);

/*
 */
DTNACL_API void dtnaclCoreUUIDToCharString(const DTNACL_Core_UUID &uuid, char *buffer);
DTNACL_API DTNACL_Core_UUID dtnaclCoreCharStringToUUID(const char *buffer);
DTNACL_API DTNACL_Core_UUID dtnaclCoreGenerateUUID();

#ifdef __cplusplus
}
#endif
