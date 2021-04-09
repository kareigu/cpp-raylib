#include <raylib-cpp.hpp>
#include <string>
#include <tuple>
#include "app_state.hpp"
#include "renderer.hpp"

int main() {

    AppState app_state(800, 450);
    AppRenderer app_renderer(&app_state);

    raylib::Window w(app_state.screen_resolution[0], app_state.screen_resolution[1], "Raylib C++");

    
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        if(IsKeyPressed(KEY_F1))
            app_state.debug_visible = !app_state.debug_visible;

        app_state.update_values();
        app_renderer.update();

        // Draw
        BeginDrawing();

        app_renderer.render();

        EndDrawing();
    }

    return 0;
}