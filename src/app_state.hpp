#pragma once
#include "raylib-cpp.hpp"
#include "grid.hpp"
#include "cube.hpp"

enum StateTextTypes {
    FPS,
    Delta,
    Elapsed,
};

struct AppState {

    int fps;
    float delta;
    double elapsed;
    int screen_resolution[2];
    bool debug_visible = true;
    raylib::Window* w;
    Grid grid;
    Cube* cube;

    AppState(int res_x, int res_y) {
        this->screen_resolution[0] = res_x;
        this->screen_resolution[1] = res_y;
        this->update_values();
        this->grid = Grid(res_x, res_y);
        this->cube = new Cube();
    }

    void update_values() {
        this->fps = GetFPS();
        this->delta = GetFrameTime();
        this->elapsed = GetTime();
    }

    std::string get_text(StateTextTypes type) {
        std::string text;
        switch(type) {
            case FPS:
                text = std::to_string(this->fps) + " fps";
                break;
            case Delta:
                text = std::to_string(this->delta) + " s";
                break;
            case Elapsed:
                text = std::to_string(this->elapsed) + " seconds";
                break;
            default:
                text = "Invalid value type";
                break;
        }

        return text;
    }

    void run_update() {
        if(this->screen_resolution[0] != this->w->GetScreenWidth() || this->screen_resolution[1] != this->w->GetScreenHeight()) {
            int width = this->screen_resolution[0], height = this->screen_resolution[1];
            w->SetSize(width, height);
            grid.height = height;
            grid.width = width;
        }
    }
};

