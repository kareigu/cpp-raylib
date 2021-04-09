#pragma once
#include "raylib-cpp.hpp"

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

    AppState(int res_x, int res_y) {
        this->screen_resolution[0] = res_x;
        this->screen_resolution[1] = res_y;
        this->update_values();
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
};

