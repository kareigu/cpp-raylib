#pragma once
#include <raylib-cpp.hpp>

struct Cube {
  Vector3 cubePosition;
  Vector2 cubeScreenPosition;
  Color primary;
  Color outline;

  void render() {
    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, primary);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, outline);
  }

  Cube(Color primary_color = RED, Color outline_color = MAROON) {
    this->primary = primary_color;
    this->outline = outline_color;
  }
};
