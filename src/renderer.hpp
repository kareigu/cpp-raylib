#pragma once
#include "raylib-cpp.hpp"
#include "app_state.hpp"
#include "cube.hpp"


struct AppRenderer {
  AppState* app_state;
  raylib::Camera3D* camera;

  raylib::Color text_color;
  raylib::Color debug_text_color;
  raylib::Color object_color;

  int rect_x;

  AppRenderer(AppState* app_state, raylib::Camera3D* camera) {
    this->app_state = app_state;
    this->camera = camera;
    this->text_color = raylib::Color(WHITE);
    this->object_color = raylib::Color(RED);
    this->debug_text_color = raylib::Color(PINK);
  }

  void render() {
    ClearBackground({15, 21, 28, 255});


    //object_color.DrawRectangle(rect_x, 200, 50, 50);


    camera->BeginMode3D();
    {
      DrawGrid(50, 1.0f);

      /* for(float x = -5.0f; x < 5.0f; x += 2.0f) {
        for(float y = -5.0f; y < 5.0f; y += 2.0f) {
          int roll = GetRandomValue(0, 1);
          Color fill_color = roll > 0 ? BLACK : WHITE;
          Color outline_color = roll < 0 ? BLACK : WHITE;
          Cube new_cube = (fill_color, outline_color);
          new_cube.cubePosition.x = x;
          new_cube.cubePosition.z = y;
          new_cube.cubePosition.y = roll;
          new_cube.render();
        }
      } */
      
      for(int x = 0; x < app_state->grid.size_x; x++) {
        for(int z = 0; z < app_state->grid.size_z; z++) {
          app_state->grid.cubes[x * app_state->grid.size_z + z].render();
        }
      }

      this->app_state->cube->render();
    }
    camera->EndMode3D();



    if(app_state->debug_visible) {
      debug_text_color.DrawText(app_state->get_text(FPS), 10, 10, 20);
      debug_text_color.DrawText(app_state->get_text(Delta), 10, 30, 20);
      debug_text_color.DrawText(app_state->get_text(Elapsed), 10, 50, 20);
    }

    if(app_state->paused) {
      int x = app_state->screen_resolution[0] / 2 - 70;
      raylib::Color(BLACK).DrawRectangle(x - 2, 8, 142, 36);
      text_color.DrawText("PAUSED", x, 10, 34);
    }
  }

  void update() {
    if(!app_state->paused) {
      this->rect_x = std::sin(app_state->elapsed) * 200 + 400;
      this->camera->Update();
      Cube* cube = app_state->cube;
      cube->cubePosition.x = std::sin(app_state->elapsed) * 5.0;
      cube->cubePosition.z = std::cos(app_state->elapsed) * 5.0;
      cube->cubeScreenPosition = GetWorldToScreen((Vector3){cube->cubePosition.x, cube->cubePosition.y + 2.5f, cube->cubePosition.z}, *this->camera);
    }
  }
};