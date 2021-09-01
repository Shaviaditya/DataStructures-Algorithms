//List of Headers included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <math.h>
//Design of the structure
struct details
{
    char *name;
    char *status;
    int hour;
    int min;
    int sec;
};
int main()
{
    //Opening the file to read the data from the CSV file
    FILE *fp = fopen("sheet.csv", "r");
    //Initializing an array of structures to store the data
    struct details dt[132];
    int mx = 0;
    if (!fp)
    {
        //If no such file present shall show error msg in console
        printf("No file found!\n");
    }
    else
    {
        char buffer[1024];
        char *a, *b, *c;
        int row = 0, col = 0, i = 0;
        //Loop to get the data row=wise from csv file
        while (fgets(buffer, sizeof(buffer), fp))
        {
            {
                //Subrata Nandi,Joined"3/6/20212:52:54 PM"
                col = 0;
                row++;
                if (row == 1)
                    continue;
                char *value = strtok(buffer, ","); //strtok function of extract the pure data required from the csv unicode data
                while (value)
                {
                    if (col == 0)
                    {
                        //helper variable to get the name
                        a = value;
                    }
                    if (col == 1)
                    {
                        //helper variable ti get the statuses
                        b = (value);
                    }
                    if (col == 3)
                    {
                        //helper variable to get the exact time i.e HH:MM:SS
                        c = (value);
                    }
                    //TO get new parts of the buffer char array everytime
                    value = strtok(NULL, ",");
                    col++;
                }
                //Allocarion of memory for each structure to fill in the name, status, time
                //For Name
                dt[i].name = (char *)malloc(strlen(a) + 1);
                strcpy(dt[i].name, a);

                //storing maxlength to fix displaying of data
                mx = (mx > strlen(dt[i].name)) ? (mx) : (strlen(dt[i].name));

                //For Status
                dt[i].status = (char *)malloc(strlen(b) + 1);
                strcpy(dt[i].status, b);

                //For time in separated manner as hours,minutes,seconds
                //For hours
                char *hr = (char *)calloc(1, &c[2] - &c[1] + 1);
                memcpy(hr, &c[1], &c[2] - &c[1]);
                //Conversion of string->int
                dt[i].hour = atoi(hr);

                //For minutes
                char *mn = (char *)calloc(1, &c[5] - &c[3] + 1);
                memcpy(mn, &c[3], &c[5] - &c[3]);
                dt[i].min = atoi(mn);

                //For seconds
                char *sc = (char *)calloc(1, &c[8] - &c[6] + 1);
                memcpy(sc, &c[6], &c[8] - &c[6]);
                dt[i].sec = atoi(sc);
            }
            i = i + 1;
        }
        int cnt = 0, s = 0, tt = (2 * 3600 + 60 * 50);
        //Headers of each Columns
        printf("%s", "Name of Attendees");
        /*
        for(int k=0;k<(mx-strlen(dt[i].name));k++){
            printf(" ");
        }
        */
        printf("\t\t%s \t\t%s\n", ("Time Left/Joined"), ("Percentage of attendance in class"));

        //Looping via each struct
        for (int i = 0; i < 131; i++)
        {
            int start = 0, start2 = 0, end = 0, end2 = 0;
            //Removing multiple occurances of same names who had diff statuses by using a pair-wise Linear Search Algo
            if (strcmp(dt[i].name, dt[i + 1].name) != 0)
            {
                if (strcmp(dt[i].status, "Joined") == 0)
                {
                    s = s + ((5 * 3600) - ((dt[i].sec) + ((dt[i].min + 1) * 60) + (dt[i].hour * 3600)));
                }
                printf("%s", dt[i].name);
                for (int k = 0; k < (mx - strlen(dt[i].name)); k++)
                {
                    printf(" ");
                }
                printf("\t%d \t\t\t%f\n", cnt + 1, ((float)100 * s / tt));
                //Restroing defaults for next iteration
                cnt = 0;
                s = 0;
            }
            else
            {

                //Calculations of time of presence by a simple model on seconds theory by using 00:00:00 as reference
                if (strcmp(dt[i].status, "Joined") == 0 && strcmp(dt[i + 1].status, "Left") == 0)
                {
                    s = s + (((dt[i + 1].sec) + ((dt[i + 1].min) * 60) + (dt[i + 1].hour * 3600)) - ((dt[i].sec) + ((dt[i].min) * 60) + (dt[i].hour * 3600)));
                }
                cnt++;
            }
        }
        //Closing the wkstation...
        fclose(fp);
    }
    //End
    return 0;
}