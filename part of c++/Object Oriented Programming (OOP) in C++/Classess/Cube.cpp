#include "Cube.h"

double basri::Cube::getVolume() {
  return length_ * length_ * length_;
}

double basri::Cube::getSurfaceArea() {
  return 6 * length_ * length_;
}

void basri::Cube::setLength(double length) {
  length_ = length;
}