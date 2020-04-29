#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <httproto/httproto.h>

#include "protocols.h"

void debug_print(const httproto_protocol *protocol)
{
    fprintf(stdout, "type:    %d\n", protocol->type);
    fprintf(stdout, "version: %d\n", protocol->version);
    fprintf(stdout, "method:  %d\n", protocol->method);
    fprintf(stdout, "status:  %d\n", protocol->status_code);
    fprintf(stdout, "uri:     %s\n", httproto_protocol_get_uri(protocol));
    fprintf(stdout, "path:    %s\n", httproto_protocol_get_path(protocol));
    fprintf(stdout, "query:   %s\n", protocol->query_string);
    fprintf(stdout, "headers: %lu\n", protocol->headers->length);
    fprintf(stdout, "content-length: %d\n", protocol->content_length);
    fprintf(stdout, "content: %s\n", protocol->content);
    fprintf(stdout, "\n");
}

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
    debug_print(protocol);

    httproto_protocol_free(protocol);


    protocol = httproto_protocol_create(HTTPROTO_REQUEST);
    httproto_protocol_parse(protocol, requests[1], strlen(requests[1]));

    assert(strcmp(httproto_protocol_get_uri(protocol), "/hardboiled65?tab=repositories") == 0);
    assert(strcmp(httproto_protocol_get_path(protocol), "/hardboiled65") == 0);
    assert(strcmp(httproto_protocol_get_query_string(protocol), "tab=repositories") == 0);
    debug_print(protocol);

    httproto_protocol_free(protocol);

    /* Test responses. */
    protocol = httproto_protocol_create(HTTPROTO_RESPONSE);
    httproto_protocol_parse(protocol, responses[0], strlen(responses[0]));

    debug_print(protocol);

    return 0;
}
