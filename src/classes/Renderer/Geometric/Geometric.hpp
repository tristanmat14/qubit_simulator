#pragma once
#include "RenderObject.hpp"

class Geometric : public RenderObject {
    /**
     * operator== for Geometric objects only compare geometric equality.
     * Properties such as color or anything unrelated to a geometric property is
     * not compared in the equality of the two objects.
     */
    virtual bool operator==(const RenderObject& other) const = 0;
};
