#include <ncurses.h>

int main() {
    initscr();              
    start_color();          
    use_default_colors();   

    init_pair(1, COLOR_WHITE, COLOR_WHITE); 
    attron(COLOR_PAIR(1));  

    for (int y = 0; y < LINES; y++) {
        for (int x = 0; x < COLS; x++) {
            mvaddch(y, x, ' '); 
        }
    }

    refresh();              
    getch();                
    endwin();               
    return 0;
}
