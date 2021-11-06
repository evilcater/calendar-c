#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char * FindEvent(int Fyear,int Fmonth,int Fday) {
    // init file pointer
    FILE *fp;
    // init year, month, day variables
    int year;
    int month;
    int day;
    // Allocate memory for event pointer => will
    // be returned if an event is found
    // We allocate memory because it's a local variable
    char *event = malloc(sizeof(char) * 100);
    // data var will contain each event iterated
    char data[100];
    // Event Array
    char EventArray[4][100];
    // Line delimitor
    char del[] = " ";
    // Open File
    fp = fopen("calendar.txt","r");
    int i;
    while(fgets(data, 100, fp) != NULL)
    {
        i=0;
        char *DataArray = strtok(data, del);

        while (DataArray != NULL){
            // Append to DataArray
            strcpy(EventArray[i],DataArray);
            DataArray = strtok(NULL, del);
            i+=1;
        }
        // Convert date to int
        year = atoi(EventArray[0]);
        month = atoi(EventArray[1]);
        day = atoi(EventArray[2]);
        if (day == Fday && month == Fmonth && year == Fyear){
            fclose(fp);
            sscanf(EventArray[3],"%s",event);
            return event;
        }
    }
    fclose(fp);
    return false;
}

char * ParseEvent(char *event){
    char nevent[90] = "\0";
    char *test = " ";
    size_t evlen = strlen(event);
    char c[2] = "\0";
    for(int i=0;i<evlen;i++){
        c[0] = event[i];
        if(event[i] == test[0]){
            strcat(nevent,"_");
        }
        else{
            strcat(nevent,c);
        }

    }
    char *ptr = malloc(100*sizeof(char));
    strcpy(ptr,nevent);
    return ptr;
}

