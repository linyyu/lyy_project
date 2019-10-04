
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

#define LOCAL_ESCAPE_KEY 27

int main()
{
        int key;
        initscr();
        crmode();

        keypad(stdscr, TRUE);
        noecho();
        clear();
        mvprintw(5,5,"key pad demonstration. press 'q' to quit");

        while(key != ERR && key != 'q')
        {
                move(7,5);
                clrtoeol();
                if((key >= 'A' && key <= 'Z') || (key >='a') && (key <= 'z'))
                {
                        printw("Key was %c",(char)key);
                }
                else
                {
                        switch(key)
                        {
                                case LOCAL_ESCAPE_KEY: printw("%s", "Escape key"); break;
                                case KEY_END: printw("%s","END key");   break;
                                case KEY_BEG: printw("%s","BEGINGNING KEY"); break;
                                case KEY_RIGHT: printw("%s", "KEY_RIGHT"); break;
                                case KEY_LEFT: printw("%s", "KEY_LEFT"); break;
                                case KEY_UP: printw("%s","KEY_UP");break;
                                case KEY_DOWN: printw("%s","KEY_DOWN"); break;
                                default: printw("Unmached -%d",key); break;
                        }
                }
                refresh();
                key = getch();
        }
        endwin();
        exit(EXIT_SUCCESS);
}
