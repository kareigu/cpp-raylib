#include <raylib-cpp.hpp>
#include <string>
#include <tuple>
#include "app_state.hpp"
#include "renderer.hpp"
#include "input_handler.hpp"

int main() {

    AppState app_state(800, 450);
    AppRenderer app_renderer(&app_state);
    InputHandler input_handler(&app_state);

    raylib::Window w(app_state.screen_resolution[0], app_state.screen_resolution[1], "Raylib C++");

    
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        input_handler.check_inputs();

        app_state.update_values();
        app_renderer.update();

        if(app_state.screen_resolution[0] != w.GetScreenWidth() || app_state.screen_resolution[1] != w.GetScreenHeight())
            w.SetSize(app_state.screen_resolution[0], app_state.screen_resolution[1]);

        // Draw
        BeginDrawing();

        app_renderer.render();

        EndDrawing();
    }

    return 0;
}