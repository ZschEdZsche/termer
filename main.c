#define __USE_XOPEN
#define _GNU_SOURCE

#include <ncurses.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//#include "termer_chars.h"
#include "big_font.h"

// function declaration
void help_func();

void draw_number(int y, int x, char num);
void draw_string(int y, int x, char* s);
void strftimediff(char* buf, int size, struct tm* time, double timediff);
void count_down(char* buf, int size, struct tm* time, double timediff);

// variable declaration
const int perfect_pizza_time = 13*60; // in sec
bool timer_end = false;

// debug shit
bool debug_flag = 1;

int main(int argc, char *argv[]) {
    // arg parsing
    int c;
    char *user_time = NULL;
    char *shell_cmd = NULL;
    int help_flag = false;

    opterr = 0;
    while((c = getopt(argc, argv, "ht:e:")) != -1) {
        switch(c) {
            case 'h':
                help_func();
                help_flag = true;
                break;

            case 't':
                user_time = optarg;
                break;

            case 'e':
                shell_cmd = optarg;
                break;

            case '?':
                if(optopt == 't' || optopt == 'e') {
                    fprintf(stderr,
                            "Option -%c requires an argument.\n",
                            optopt);
                }
                else if(isprint(optopt)) {
                    fprintf(stderr,
                            "Unknown Option -%c'.\n", optopt);
                }
                else {
                    fprintf(stderr,
                            "Unknown Option Character `\\x%x'.\n",
                            optopt);
                }
                return 1;
            default:
                abort();
                break;
        }
    }

    for(int i=optind; i<argc; i++) {
        printf("Non-Option argument %s\ntry -h for help text.\n", argv[i]);
    }

    if(help_flag) {
        return 0;
    }

    // ncurses setup
    char ch;
    time_t curr_time, start_time, tmp_time;

    uint64_t time_diff;
    char time_buf[10];

    WINDOW* screen = initscr();
    raw();
    noecho();
    timeout(1000); // nonblocking
    curs_set(0); // hide cursor

    // init timer
    struct tm timer_time;
    timer_time.tm_sec = 0;
    timer_time.tm_min = 0;
    timer_time.tm_hour = 0;

    if(user_time) {
        strptime(user_time, "%H:%M:%S", &timer_time);
    }

    time(&start_time);

    while(1) {

        time(&curr_time);
        double time_diff = difftime(curr_time, start_time);


        if(user_time) { // count down
            count_down(time_buf, 9, &timer_time, time_diff);
            if (timer_end) {
                break;
            }
        }
        else { // count up
            strftimediff(time_buf, 9, &timer_time, time_diff);
        }

        draw_string(0, 0, time_buf);

        ch = getch();
        if(ch == 'q' || ch == 27) { // q oder Escape
            break;
        }


        refresh();
        erase();
    }

    endwin();
    if(shell_cmd) {
        system(shell_cmd);
    }
    return 0;
}

void strftimediff(char* buf, int size, struct tm* time, double timediff) {
    time->tm_sec  = (int) timediff % 60;
    time->tm_min  = (int) timediff / 60 % 60;
    time->tm_hour = (int) timediff / 60 / 60 % 24;
    //strftime(buf, size, "%H:%M:%S", time);
    strftime(buf, size, "%M:%S", time);
}

void count_down(char* buf, int size, struct tm* time, double timediff) {
    if(time->tm_sec == 0 && time->tm_min == 0 && time->tm_hour == 0) {
        strftime(buf, size, "%H:%M:%S", time);
        timer_end = true;
        return; // timer ende
    }

    if(time->tm_sec == 0 && time->tm_min > 0) {
        time->tm_min  -= 1;
        time->tm_sec  = 60;
    }

    if(time->tm_sec == 0 && time->tm_min == 0 && time->tm_hour > 0) {
        time->tm_hour -= 1;
        time->tm_min  = 59;
        time->tm_sec  = 60;
    }

    time->tm_sec  -= 1;
    //strftime(buf, size, "%H:%M:%S", time);
    strftime(buf, size, "%M:%S", time);
}

void draw_number(int y, int x, char num) {
    if(isdigit(num)) {
        for(int i=0; i<CHAR_H; i++) {
            for(int j=0; j<CHAR_W; j++) {
                mvprintw(y+i, x+j, "%c", numbers[num-48][i][j]);
            }
        }
    }
    else {
        for(int i=0; i<CHAR_H; i++) {
            for(int j=0; j<CHAR_W; j++) {
                mvprintw(y+i, x+j, "%c", colon[i][j]);
            }
        }
    }
}

void draw_string(int y, int x, char* s) {
    int len = strlen(s);
    for(int i=0; i<len; i++) {
        draw_number(y, x+(2+CHAR_W)*i, s[i]);
    };
}

void help_func() {
    printf("\n");
    printf("Terminal Countdown\n");
    printf("if no option is specified the timer will count down from 13 Minutes, the perfect pizza baking time.\n");
    printf("usage:\n");
    printf("    termer [options}\n");
    printf("options:\n");
    printf("    -t <time>   specify countdown time, format: HH:MM:SS\n");
    printf("    -e <arg>    command to execute after timer ends (only with -t flag)\n");
    printf("    -h          show this help text\n");
    printf("\n");
}
