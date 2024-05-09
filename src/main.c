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
                b = 0; // pour quitter
                break;

            case 3:
                char kw[50];
                printf("Keyword?\n");

                // Vider le buffer d'entrée standard avant d'utiliser fgets
                fflush(stdin);
                fgets(kw, sizeof(kw), stdin);

                // Supprimer le caractère de nouvelle ligne
                if (kw[strlen(kw) - 1] == '\n')
                    kw[strlen(kw) - 1] = '\0';

                // Réinitialiser le buffer avant d'appeler fetch_quote_by_kw
                memset(buffer, 0, sizeof(buffer));

                fetch_quote_by_kw(buffer,sizeof(buffer), kw);
                parse_json_response(buffer);
                break;


            default:
                printf("No quote for you dummy.\n");
                //fetch_api(buffer, sizeof(buffer));
                //parse_json_response(buffer);
                break;
        }
    }
    return 0;
}



// simple quote
// int main(){
//     char buffer[900];
//     fetch_api(buffer, sizeof(buffer));
//     parse_json_response(buffer);
//     return 0;
// }