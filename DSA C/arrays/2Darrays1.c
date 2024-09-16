#include <stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>

#define MAX_PEOPLE 100
#define MAX_GENRE_LENGTH 50
#define MAX_GENRES MAX_PEOPLE

typedef struct 
{
    char name[100];
    char movie[100];
    char genre[MAX_GENRE_LENGTH];
} SurveyData;

void inputSurveyData(SurveyData surveys[], int n);
void findMostWatchedGenres(SurveyData surveys[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    if (n <= 0)
    {
        return 0;
    }
    SurveyData surveys[MAX_PEOPLE];
    inputSurveyData(surveys, n);
    findMostWatchedGenres(surveys, n);
    return 0;
}

void inputSurveyData(SurveyData surveys[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fgets(surveys[i].name, sizeof(surveys[i].name), stdin);
        surveys[i].name[strcspn(surveys[i].name, "\n")] = 0; 
        fgets(surveys[i].movie, sizeof(surveys[i].movie), stdin);
        surveys[i].movie[strcspn(surveys[i].movie, "\n")] = 0; 
        fgets(surveys[i].genre, sizeof(surveys[i].genre), stdin);
        surveys[i].genre[strcspn(surveys[i].genre, "\n")] = 0; 
    }
}

void findMostWatchedGenres(SurveyData surveys[], int n)
{
    int genreCount[MAX_GENRES] = {0}; 
    char genres[MAX_GENRES][MAX_GENRE_LENGTH]; 
    int genreIndex = 0;
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < genreIndex; j++) 
        {
            if (strcmp(surveys[i].genre, genres[j]) == 0)
            {
                genreCount[j]++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(genres[genreIndex], surveys[i].genre);
            genreCount[genreIndex]++;
            genreIndex++;
        }
    }
    int maxCount = 0;
    for (int i = 0; i < genreIndex; i++)
    {
        if (genreCount[i] > maxCount)
        {
            maxCount = genreCount[i];
        }
    }
    int printed = 0;
    for (int i = 0; i < genreIndex; i++)
    {
        if (genreCount[i] == maxCount)
        {
            if (printed > 0)
            {
                printf(" ");
            }
            printf("%s", genres[i]);
            printed = 1;
        }
    }
    printf("\n");
}