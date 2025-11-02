#pragma once
#include "glm/vec4.hpp"

class Color {
private:
    const glm::vec4 color; // RGBA
public:
    Color() : color(0.0f, 0.1f, 0.3f, 1.0f) {}
    explicit Color(float r, float g, float b, float a = 1.0f) : color(r, g, b, a) {}

    const glm::vec4& getColor() const {
        return color;
    }  
};
