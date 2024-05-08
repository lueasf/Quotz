#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // enable using the size_t type
#include "api.h"
#include "pars.h"

int main(){
    char buffer[900];
    fetch_api(buffer, sizeof(buffer));
    parse_json_response(buffer);
    return 0;
}