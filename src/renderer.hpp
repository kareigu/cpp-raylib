#pragma once
#include "raylib-cpp.hpp"
#include "app_state.hpp"


struct AppRenderer {
  AppState* app_state;

  raylib::Color text_color;
  raylib::Color object_color;

  int rect_x;

  AppRenderer(AppState* app_state) {
    this->app_state = app_state;
    this->text_color = raylib::Color(WHITE);
    this->object_color = raylib::Color(RED);
  }

  void render() {
    ClearBackground({15, 21, 28, 255});

    if(app_state->debug_visible) {
      text_color.DrawText(app_state->get_text(FPS), 10, 10, 20);
      text_color.DrawText(app_state->get_text(Delta), 10, 30, 20);
      text_color.DrawText(app_state->get_text(Elapsed), 10, 50, 20);
    }

    object_color.DrawRectangle(rect_x, 200, 50, 50);
  }

  void update() {
    this->rect_x = std::sin(app_state->elapsed) * 200 + 400;
  }
};