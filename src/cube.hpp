#pragma once
#include <raylib-cpp.hpp>

struct Cube {
  Vector3 cubePosition;
  Vector2 cubeScreenPosition;
  Color primary;
  Color outline;

  void render() {
    DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, this->primary);
    DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, this->outline);
  }

  Cube(Color primary_color, Color outline_color) {
    this->primary = primary_color;
    this->outline = outline_color;
  }

  Cube() {
    this->primary = RED;
    this->outline = BLACK;
  }
};
