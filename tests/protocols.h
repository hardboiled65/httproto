const char *requests[] = {
    /* Simple GET */
    "GET / HTTP/1.1\r\n" \
    "Host: example.com\r\n" \
    "User-Agent: libhttproto/0.1\r\n" \
    "Accept: */*\r\n" \
    "\r\n",

    /* GET with query params */
    "GET /hardboiled65?tab=repositories HTTP/1.1\r\n" \
    "Host: github.com\r\n" \
    "User-Agent: libhttproto/0.1\r\n" \
    "\r\n"
};

const char *responses[] = {

};
