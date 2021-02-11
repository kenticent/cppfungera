#include "App.h"
#include "Organism.h"
#include "Queue.h"

App::App()
{
    Memory *memory = Memory::get_instance();
    memory->init(5000, 5000);
    std::size_t nlines, ncols;
    nlines = memory->load_genome("initial.gen", 2500, 2500, ncols);
    begin_i_ = 2500;
    begin_j_ = 2500;
    Organism organism(nlines, ncols, begin_i_, begin_j_);

    initscr();

    getmaxyx(stdscr, max_y_, max_x_);
}

void App::run()
{
    draw_mem();

    getch();
    endwin();
}

void App::draw_mem()
{
    std::size_t i = begin_i_;
    for (int y = 0; y < max_y_; ++y) {
        std::size_t j = begin_j_;
        int x = 0;
        move(y, x);
        for ( ; x < max_x_; ++x)
            addch((*Memory::get_instance())(i+y, j+x));
    }
    refresh();
}