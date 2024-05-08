#include <stddef.h> // enable using the size_t type

// store response in buffer
size_t cb(void* d, size_t n, size_t l, void* p);

// collect data from api
void fetch_api(char* buffer, int buffer_size);