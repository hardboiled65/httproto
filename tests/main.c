#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <httproto/httproto.h>

#include "protocols.h"

int main(int argc, char *argv[])
{
    httproto_protocol *protocol;

    /* Test requests. */
    protocol = httproto_protocol_create(HTTPROTO_REQUEST);
    httproto_protocol_parse(protocol, requests[0], strlen(requests[0]));

    assert(protocol->method == HTTPROTO_GET);
    assert(strcmp(httproto_protocol_get_uri(protocol), "/") == 0);
    assert(strcmp(httproto_protocol_get_path(protocol), "/") == 0);
    assert(strcmp(httproto_protocol_get_header(protocol, "Host"), "example.com") == 0);

    httproto_protocol_free(protocol);


    protocol = httproto_protocol_create(HTTPROTO_REQUEST);
    httproto_protocol_parse(protocol, requests[1], strlen(requests[1]));

    assert(strcmp(httproto_protocol_get_uri(protocol), "/hardboiled65?tab=repositories") == 0);
    assert(strcmp(httproto_protocol_get_path(protocol), "/hardboiled65") == 0);
    assert(strcmp(httproto_protocol_get_query_string(protocol), "tab=repositories") == 0);

    httproto_protocol_free(protocol);

    /* Test responses. */

    return 0;
}
