#include "api.h"
#include <curl/curl.h>
#include <stddef.h> // enable using the size_t type
#include <string.h>

size_t cb(void *d, size_t n, size_t l, void *p){ // d : pointer to the data, n : size of the data, l : nb of elements, p: pointer to some date
    size_t size = n*l; // size of data
    char* buffer = (char*)p; 
    strncat(buffer, d, size); // concatenate the data to the buffer.
    return size;
}

void fetch_api_with_url(const char* url, char* buffer, int buffer_size){
    CURL *curl = curl_easy_init(); // initialize curl
    if (curl){
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL,url); // set url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb); // set callback function 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer); // set buffer

        res = curl_easy_perform(curl); // store response
        if (res != CURLE_OK){ // CURLE_OK is a macro that is defined in curl.h : valued 0. Error if different
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res)); // fprintf for formatted output : we specify stderr(standard error) as the output
        }
        curl_easy_cleanup(curl); // oposite of curl_easy_init
    }
}

void fetch_api(char* buffer, int buffer_size){
    const char *url = "https://api.quotable.io/random";
    fetch_api_with_url(url, buffer, buffer_size);
}

void fetch_quote_by_kw(char *buffer, size_t buffer_size, const char *kw) {
    char url[100];
    snprintf(url, sizeof(url), "https://api.quotable.io/random?tags=%s", kw); // put the string in the url variable

    memset(buffer, 0, sizeof(buffer)); // clear buffer before each use !!!!

    fetch_api_with_url(url, buffer, buffer_size);
}

//     if (strlen(kw) > 0){
//         sprintf(url, "https://api.quotable.io/quotes?tags=%s", kw); // put the string in the url variable
//     } else {
//         sprintf(url, "https://api.quotable.io/random"); // same
//     }
//     fetch_api_with_url(url, buffer, buffer_size);