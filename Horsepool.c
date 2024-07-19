#include<stdio.h> 
#include<stdlib.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<time.h>
#define NO_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }
void badCharHeuristic(char* str, int size, int badchar[NO_OF_CHARS]){ 
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(char* txt, char* pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0) {
            printf("The desired pattern was found starting from position: %d\n", s);
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else

        s += max(1, j - badchar[txt[s + j]]);
    }
}


int main()
{
char txt[100];
char pat[100];
printf("Enter the text in which pattern need to be searched:\n");
scanf("%s", txt);
printf("Enter the pattern need to be searched:\n");
scanf("%s", pat);

printf("Length of text is %ld\n", strlen(txt));
printf("Length of pattern is %ld\n", strlen(pat));

struct timeval start_time,end_time;
gettimeofday(&start_time,NULL);
search(txt, pat);
gettimeofday(&end_time,NULL);

printf("Time for Harspool's algrithm is: %fmicroseconds\n",(double)end_time.tv_usec - (double)start_time.tv_usec);
struct rusage r_usage;
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory usage: %ld Kilobytes\n", r_usage.ru_maxrss);
return 0;
}
