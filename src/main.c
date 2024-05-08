#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // enable using the size_t type
#include "api.h"

int main(){
    char buffer[900];
    fetch_api(buffer, sizeof(buffer));
    printf("data caught by api: \n%s\n", buffer);
    return 0;
}