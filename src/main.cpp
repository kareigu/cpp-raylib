#include <raylib-cpp.hpp>
#include <string>

enum StateTextTypes {
    FPS,
    Delta,
    Elapsed,
};

struct AppState {

    AppState() {
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

private:
    int fps;
    float delta;
    double elapsed;
};


int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;

    AppState app_state = AppState();

    raylib::Color textColor(WHITE);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++");

    
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        app_state.update_values();

        // Draw
        BeginDrawing();
        ClearBackground({0, 0, 0, 255});
        textColor.DrawText(app_state.get_text(FPS), 10, 10, 20);
        textColor.DrawText(app_state.get_text(Delta), 10, 30, 20);
        textColor.DrawText(app_state.get_text(Elapsed), 10, 50, 20);
        EndDrawing();
    }

    return 0;
}