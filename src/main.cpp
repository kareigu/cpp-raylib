#include <raylib-cpp.hpp>
#include <string>
#include <tuple>
#include "app_state.hpp"
#include "renderer.hpp"
#include "input_handler.hpp"

int main() {
  AppState app_state(800, 450);
  InputHandler input_handler(&app_state);
  raylib::Window w(app_state.screen_resolution[0], app_state.screen_resolution[1], "Raylib C++");
  app_state.w = &w;

  raylib::Camera camera(
    raylib::Vector3(10.0f, 10.0f, 10.0f),
    raylib::Vector3(),
    raylib::Vector3(0.0f, 1.0f, 0.0f),
    45.0f,
    CAMERA_PERSPECTIVE);

  camera.SetMode(CAMERA_FREE);
  AppRenderer app_renderer(&app_state, &camera);


  

  
  // Main game loop
  while (!w.ShouldClose()) // Detect window close button or ESC key
  {
    // Update
    input_handler.check_inputs();
    app_state.update_values();
    app_state.run_update();
    app_renderer.update();

    // Draw
    BeginDrawing();
    {
      app_renderer.render();
    }
    EndDrawing();
  }

  return 0;
}