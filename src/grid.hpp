#pragma once

struct Grid {
  int width;
  int height;

  Grid(int width = 0, int height = 0) {
    this->width = width / 100;
    this->height = height / 100;
  }

  void resize_grid(int width, int height) {
    this->width = width / 100;
    this->height = height / 100;
  }
};