#include <stdio.h>
#include <stdlib.h>

int Create(){
    char *year = malloc(4 * sizeof(char));
    char *month = malloc(2 * sizeof(char));
    char *day = malloc(2 * sizeof(char));
    char *event = malloc(100 * sizeof(char));
    FILE *fp;
    printf("Enter year : ");
    scanf("%[^\n]%*c",year);
    printf("Enter month : ");
    scanf("%[^\n]%*c",month);
    printf("Enter day : ");
    scanf("%[^\n]%*c",day);
    printf("Enter event : ");
    scanf("%[^\n]%*c",event);
    fp=fopen("calendar.txt","a");
    strcpy(event,ParseEvent(event));
    fprintf(fp, "%s %s %s %s",year,month,day,event);
    fclose(fp);
    free(year);
    free(month);
    free(day);
    free(event);
    return 0;
}
