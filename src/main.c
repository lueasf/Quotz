#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // enable using the size_t type
#include <string.h> // for strlen
#include "api.h"
#include "pars.h"

int main(){
    printf("Welcome to the Quote Generator\n\n");
    char buffer[900];
    int b = 1;
    int case_5 = 0; // for special case
    while(b){
        int input;
        printf("Type 1 for an inspirational quote.\n");
        printf("Type 2 to quit.\n");
        printf("Type 3 for a keyword quote.\n");
        scanf("%d", &input);

        memset(buffer, 0, sizeof(buffer)); // clear buffer before each use !!!!

        switch (input){
            case 1:
                printf("\n\n");
                printf("An inspirational quote\n");
                fetch_api(buffer, sizeof(buffer));
                parse_json_response(buffer);
                fflush(stdin);
                printf("\n\n");
                break;

            case 2:
                b = 0; // to quit
                break;

            case 3: // choose a keyword 
                printf("Choose a keyword by typing the number:\n");
                printf("1. Wisdom.\n");
                printf("2. Success.\n");
                printf("3. Famous Quote.\n");
                printf("4. Life.\n");
                printf("5. Custom keyword.\n");
                printf("\t Such as Happiness, Faith, Friendship, Love, etc.\n\n");

                int keyword;
                scanf("%d", &keyword);
                printf("\n\n");

                const char *kw;
                switch (keyword) {
                    case 1:
                        kw = "Wisdom";
                        break;
                    case 2:
                        kw = "Success";
                        break;
                    case 3:
                        kw = "Famous Quote";
                        break;
                    case 4:
                        kw = "Life";
                        break;
                    case 5: // own keyword
                        case_5 = 1;
                        printf("Enter your own keyword:\n");
                        char custom_kw[50];
                        scanf("%s", custom_kw);
                        printf("\n\n");
                        fetch_quote_by_kw(buffer, sizeof(buffer), custom_kw);
                        parse_json_response(buffer);
                        break;

                    default:
                        printf("Invalid keyword\n");
                        continue;
                }
                if (case_5)
                    break;
                printf("\n\n");
                fetch_quote_by_kw(buffer, sizeof(buffer), kw);
                parse_json_response(buffer);
                printf("\n\n");
                break;

            default:
                printf("No quote for you dummy.\n");
                break;
        }
    }
    return 0;
}