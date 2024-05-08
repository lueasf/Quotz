#include <stdio.h>
#include <cjson/cJSON.h> // bibli cJSON
#include "pars.h"

void parse_json_response(const char* json_resp){
    cJSON* root = cJSON_Parse(json_resp);
    if (root == NULL){
        fprintf(stderr, "Error from cJSON_Parse: %s\n", cJSON_GetErrorPtr());
    }

    cJSON* content = cJSON_GetObjectItem(root, "content"); // collect content from root
    cJSON* author = cJSON_GetObjectItem(root, "author");
    cJSON* tags = cJSON_GetObjectItem(root, "tags");

    if (content && author){
        printf("'%s'\n", content->valuestring); 
        printf("By %s\n", author->valuestring);
    } else {
        printf("Error: content or author not found\n");
    }

    cJSON_Delete(root); 
}