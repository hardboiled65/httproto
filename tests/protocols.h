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
    /* Modified response from example.com */
    "HTTP/1.1 200 OK\r\n"
    "Age: 439931\r\n"
    "Cache-Control: max-age=604800\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n"
    "Date: Wed, 29 Apr 2020 00:59:06 GMT\r\n"
    "Etag: \"3147526947+ident\"\r\n"
    "Expires: Wed, 06 May 2020 00:59:06 GMT\r\n"
    "Last-Modified: Thu, 17 Oct 2019 07:18:26 GMT\r\n"
    "Server: ECS (sjc/4E68)\r\n"
    "Vary: Accept-Encoding\r\n"
    "X-Cache: HIT\r\n"
    "Content-Length: 15\r\n"
    "\r\n"
    "{\"result\":true}"
};
