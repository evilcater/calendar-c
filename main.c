#include <stdio.h>
#include <time.h>
#include "parser.c"
#include "create.c"
#include "render.c"

int main(int argc,char *argv[]){
    char *new = "new";
    if (argc==2 && !strcmp(argv[1],new)){
        Create();
    }
    else {
        time_t t = time(NULL);
        struct tm tm=*localtime(&t);
        Render(tm.tm_year+1900,tm.tm_mon+1);
    }
    return 0;
}
