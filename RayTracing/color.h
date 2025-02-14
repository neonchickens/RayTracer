#pragma once

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream& out, color pixel_color, int samples_per_pixel) {

    auto scale = 1.0 / samples_per_pixel;
    color scaled_pixel_color = pixel_color * scale;
    auto r = sqrt(scaled_pixel_color.x());
    auto g = sqrt(scaled_pixel_color.y());
    auto b = sqrt(scaled_pixel_color.z());

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0, 0.999)) << '\n';
}

#endif