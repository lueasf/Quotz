#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // enable using the size_t type
#include "api.h"
#include "pars.h"

int main(){
    printf("Welcome to the Quote Generator\n\n");
    char buffer[900];
    int b = 1;
    while(b){
        int input;
        printf("Type 1 for an inspirational quote.\n");
        printf("Type 2 to quit.\n");
        printf("Type 3 for a keyword quote.\n");
        scanf("%d", &input);

        switch (input){
            case 1:
                fetch_api(buffer, sizeof(buffer));
                parse_json_response(buffer);
                break;

            case 2:
                b = 0; // to quit
                break;

            case 3:
                char kw[50];
                printf("Keyword?\n");
                scanf("%s", kw); // kw  not &kw because it is already a pointer dummy
                fetch_quote_by_kw(buffer,sizeof(buffer), kw);
                parse_json_response(buffer);
                break;

            default:
                printf("An inspirational quote\n");
                fetch_api(buffer, sizeof(buffer));
                parse_json_response(buffer);
                break;
        }
    }
    return 0;
}