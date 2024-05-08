#include <stddef.h> // enable using the size_t type

// store response in buffer
size_t cb(void* d, size_t n, size_t l, void* p);

// collect data from api
void fetch_api_with_url(const char* url, char* buffer, int buffer_size);

// collect random quote
void fetch_api(char* buffer, int buffer_size);

// collect quotes by keywords
void fetch_quote_by_kw(char* buffer, int buffer_size, const char* kw);