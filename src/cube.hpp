#pragma once
#include <raylib-cpp.hpp>

enum CubeState {
  Alive,
  Dead,
};

struct Cube {
  Vector3 cubePosition;
  Vector2 cubeScreenPosition;
  Color primary;
  Color outline;

  void render() {
    DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, this->primary);
    DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, this->outline);
  }

  Cube(CubeState state) {
    this->primary = state == Alive ? WHITE : BLACK;
    this->outline = state == Alive ? BLACK : WHITE;
  }

  Cube() {
    this->primary = RED;
    this->outline = BLACK;
  }
};
