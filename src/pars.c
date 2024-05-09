#include <stdio.h>
#include <cjson/cJSON.h> // bibli cJSON
#include <string.h>
#include "pars.h"

void parse_json_response(const char* json_resp){

    const char *json_start = strchr(json_resp, '{');
    if (json_start == NULL) {
        printf("Aucun objet JSON trouvé dans la réponse.\n");
        return;
    }

    cJSON* root = cJSON_Parse(json_start);
    if (root == NULL){
        fprintf(stderr, "Error from cJSON_Parse: %s\n", cJSON_GetErrorPtr());
    }

    cJSON* content = cJSON_GetObjectItem(root, "content"); // collect content from root
    cJSON* author = cJSON_GetObjectItem(root, "author");
    cJSON* tags = cJSON_GetObjectItem(root, "tags");

    if (content && author && tags){
        printf("'%s'\n", content->valuestring); 
        printf("By %s\n", author->valuestring);
        
        // check if tags is an array (struct linked list)
        if (cJSON_IsArray(tags)){
            printf("Tags: ");
            cJSON* tag = tags->child; // get the first tag
            while (tag){
                printf("#%s ", tag->valuestring);
                tag = tag->next; // get the next tag
            }
            printf("\n");
        } else {
            printf("Tags: %s\n", tags->valuestring);
        }

    } else {
        printf("Error: content not found\n");
    }

    cJSON_Delete(root); 
}