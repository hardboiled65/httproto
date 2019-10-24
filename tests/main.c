#include <stdlib.h>
#include <assert.h>

#include <httproto/httproto.h>

int main(int argc, char *argv[])
{
    httproto_protocol *protocol;

    /* Test requests. */
    protocol = httproto_protocol_create(HTTPROTO_REQUEST);

    httproto_protocol_free(protocol);

    /* Test responses. */

    return 0;
}
