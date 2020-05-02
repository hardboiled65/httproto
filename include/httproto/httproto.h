#ifndef _HTTPROTO_H
#define _HTTPROTO_H

#include <stdlib.h>
#include <stdint.h>
#ifndef cplusplus
    #include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


enum httproto_type {
    HTTPROTO_REQUEST,
    HTTPROTO_RESPONSE,
};

typedef enum httproto_http_version {
    HTTPROTO_HTTP_1_1,
    HTTPROTO_HTTP_2,
} httproto_http_version;

enum httproto_request_method {
    HTTPROTO_CONNECT,
    HTTPROTO_DELETE,
    HTTPROTO_GET,
    HTTPROTO_HEAD,
    HTTPROTO_OPTIONS,
    HTTPROTO_PATCH,
    HTTPROTO_POST,
    HTTPROTO_PUT,
    HTTPROTO_TRACE,
};

enum httproto_status_code {
    HTTPROTO_CONTINUE               = 100,
    HTTPROTO_SWITCHING_PROTOCOLS    = 101,
    HTTPROTO_EARLY_HINTS            = 103,
    HTTPROTO_OK                     = 200,
    HTTPROTO_CREATED                = 201,
    HTTPROTO_ACCEPTED               = 202,
    HTTPROTO_NON_AUTHORITATIVE_INFORMATION  = 203,
    HTTPROTO_NO_CONTENT             = 204,
    HTTPROTO_RESET_CONTENT          = 205,
    HTTPROTO_PARTIAL_CONTENT        = 206,
    HTTPROTO_MULTIPLE_CHOICES       = 300,
    HTTPROTO_MOVED_PERMANENTLY      = 301,
    HTTPROTO_FOUND                  = 302,
    HTTPROTO_SEE_OTHER              = 303,
    HTTPROTO_NOT_MODIFIED           = 304,
    HTTPROTO_TEMPORARY_REDIRECT     = 307,
    HTTPROTO_PERMANENT_REDIRECT     = 308,
    HTTPROTO_BAD_REQUEST            = 400,
    HTTPROTO_UNAUTHORIZED           = 401,
    HTTPROTO_PAYMENT_REQUIRED       = 402,
    HTTPROTO_FORBIDDEN              = 403,
    HTTPROTO_NOT_FOUND              = 404,
    HTTPROTO_METHOD_NOT_ALLOWED     = 405,
    HTTPROTO_NOT_ACCEPTABLE         = 406,
    HTTPROTO_PROXY_AUTHENTICATION_REQUIRED  = 407,
    HTTPROTO_REQUEST_TIMEOUT        = 408,
    HTTPROTO_CONFLICT               = 409,
    HTTPROTO_GONE                   = 410,
    HTTPROTO_LENGTH_REQUIRED        = 411,
    HTTPROTO_PRECONDITION_FAILED    = 412,
    HTTPROTO_PAYLOAD_TOO_LARGE      = 413,
    HTTPROTO_URI_TOO_LONG           = 414,
    HTTPROTO_UNSUPPORTED_MEDIA_TYPE = 415,
    HTTPROTO_RANGE_NOT_SATISFIABLE  = 416,
    HTTPROTO_EXPECTATION_FAILED     = 417,
    HTTPROTO_IM_A_TEAPOT            = 418,
    HTTPROTO_UNPROCESSABLE_ENTITY   = 422,
    HTTPROTO_TOO_EARLY              = 425,
    HTTPROTO_UPGRADE_REQUIRED       = 426,
    HTTPROTO_PRECONDITION_REQUIRED  = 428,
    HTTPROTO_TOO_MANY_REQUESTS      = 429,
    HTTPROTO_REQUEST_HEADER_FIELDS_TOO_LARGE    = 431,
    HTTPROTO_UNAVAILABLE_FOR_LEGAL_REASONS      = 451,
    HTTPROTO_INTERNAL_SERVER_ERROR  = 500,
    HTTPROTO_NOT_IMPLEMENTED        = 501,
    HTTPROTO_BAD_GATEWAY            = 502,
    HTTPROTO_SERVICE_UNAVAILABLE    = 503,
    HTTPROTO_GATEWAY_TIMEOUT        = 504,
    HTTPROTO_HTTP_VERSION_NOT_SUPPORTED         = 505,
    HTTPROTO_NETWORK_AUTHENTICATION_REQUIRED    = 511,
};

typedef enum httproto_error {
    HTTPROTO_UNKNOWN, /* DO NOT USE! */
} httproto_error;

typedef char* httproto_key_value_pair[2];
struct httproto_string_dictionary {
    httproto_key_value_pair *items;
    size_t length;
    size_t capacity;
};
typedef struct httproto_string_dictionary httproto_string_dictionary;

httproto_string_dictionary* httproto_string_dictionary_create();

void httproto_string_dictionary_set(httproto_string_dictionary *dict,
    const char *key, const char *val);

const char* httproto_string_dictionary_get(
    const httproto_string_dictionary *dict, const char *key);

void httproto_string_dictionary_free(httproto_string_dictionary *dict);


struct httproto_protocol {
    enum httproto_type type;
    httproto_http_version version;
    enum httproto_request_method method;    /* Request only */
    enum httproto_status_code status_code;  /* Response only */
    char *uri;                              /* Request only */
    char *path;                             /* Request only */
    char *query_string;                     /* Request only */
    httproto_string_dictionary *headers;
    uint64_t content_length;
    char *content;
    bool valid;
};
typedef struct httproto_protocol httproto_protocol;

/**
 * @brief   Create and initialize httproto_protocol and return new allocated
 *          pointer.
 * @param   type
 *          enum httproto_type (HTTPROTO_REQUEST or HTTPROTO_RESPONSE).
 * @return  New alloated httproto_protocol struct. This should be freed using
 *          httproto_protocol_free() manually.
 */
httproto_protocol* httproto_protocol_create(enum httproto_type type);


/**
 * @brief   httproto_protocol_parse
 * @param   protocol
 * @param   data
 * @param   len
 */
void httproto_protocol_parse(httproto_protocol *protocol, const char *data, size_t len);
void httproto_protocol_set_uri(httproto_protocol *protocol, const char *uri);
const char* httproto_protocol_get_uri(const httproto_protocol *protocol);
const char* httproto_protocol_get_path(const httproto_protocol *protocol);
const char* httproto_protocol_get_query_string(const httproto_protocol *protocol);
void httproto_protocol_set_header(httproto_protocol *protocol, const char *key, const char *val);
const char* httproto_protocol_get_header(const httproto_protocol *protocol, const char *key);
void httproto_protocol_free(httproto_protocol *protocol);

const char* httproto_request_method_to_string(enum httproto_request_method method);
const char* httproto_status_code_to_string(enum httproto_status_code code);


#ifdef __cplusplus
}
#endif

#endif /* _HTTPROTO_H */
