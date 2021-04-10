#pragma once
#include "cube.hpp"

struct Grid {
  float width;
  float height;
  Cube* cubes;
  int size_x;
  int size_z;

  Grid(float width = 5.0f, float height = 5.0f) {
    this->width = width;
    this->height = height;

    this->size_x = ((int)width * 2); 
    this->size_z = ((int)height * 2);
    this->cubes = new Cube[size_x * size_z];

    for(float x = -width; x < width; x += 1.0f) {
      for(float z = -height; z < height; z += 1.0f) {
        int index = ((int)x + (int)width) * size_z + ((int)z + (int)height);

        int roll = GetRandomValue(0, 1);
        Cube new_cube(roll > 0 ? Alive : Dead);
        new_cube.cubePosition.x = x;
        new_cube.cubePosition.z = z;

        this->cubes[index] = new_cube;
      }
    }
  }
};