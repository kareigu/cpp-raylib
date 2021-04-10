#pragma once
#include <raylib-cpp.hpp>
#include "app_state.hpp"

struct InputHandler {
  AppState* app_state;

  InputHandler(AppState* app_state) {
    this->app_state = app_state;
  }

  void check_inputs() {
    if(IsKeyPressed(KEY_F1))
        app_state->debug_visible = !app_state->debug_visible;

    if(IsKeyPressed(KEY_RIGHT))
        app_state->screen_resolution[0] += 10;

    if(IsKeyPressed(KEY_LEFT))
        app_state->screen_resolution[0] -= 10;
    if(IsKeyPressed(KEY_UP))
      app_state->screen_resolution[1] += 10;

    if(IsKeyPressed(KEY_DOWN))
        app_state->screen_resolution[1] -= 10;
  }
};