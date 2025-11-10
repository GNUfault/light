/*
 * Light - Make your screen white
 * Copyright (C) 2025  Connor Thomson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
