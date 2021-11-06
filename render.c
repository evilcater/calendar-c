#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int CalcDay(int year, int month){
    if (month==2){
        if (year%4==0 && year%100!=0 || year % 400 == 0){
            return 29;
        }
        else{
            return 28;
        }
    }
    else if (month <= 7 && month%2==0 || month > 7 && month%2==1){
        return 30;
    }
    else{
        return 31;
    }
}

void RenderEvent(char *event, char *date){
    char test[] = "_";
    printf("%s : ",date);
    for (int i = 0;i<strlen(event);i++){
        char c[2]="\0";
        c[0] = event[i];
        if (c[0]==test[0]) {
            printf(" ");
        }
        else {
            printf("%s",c);
        }
    }
    printf("\n");
}



int Render(int year,int month){
    //printf("\e[1;1H\e[2J");
    char Months[12][20] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int Day = CalcDay(year, month);
    const int Lenday = Day * 2;
    printf("\n\t    %s-%d\n\n\t",Months[month-1],year);
    char Rday[200];
    char ParamEvents[Lenday][100];
    char ParamDates[Lenday][20];
    int Eventlen = 0;
    char TempDate[20];
    for (int i=1;i<=Day;i++){

        sprintf(Rday,"%d",i);
        if (FindEvent(year,month,i) != false){

            strcpy(ParamEvents[Eventlen],FindEvent(year,month,i));
            sprintf(TempDate,"%d-%d-%d",year,month,i);
            strcpy(ParamDates[Eventlen],TempDate);
            sprintf(Rday,"\033[7m%i\033[0m",i);
            Eventlen +=1;

        }

        if (i<10){

            printf(" %s ",Rday);

        }
        else{

            printf("%s ",Rday);

        }

        if (i%7==0){

            printf("\n\t");

        }
    }
    printf("\n\n");
    for (int i=0;i<Eventlen;i++){
        RenderEvent(ParamEvents[i],ParamDates[i]);
    }
}

