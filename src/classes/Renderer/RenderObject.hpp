#pragma once

class RenderObject {
public:
    virtual void draw() const = 0;
    virtual ~RenderObject() noexcept = default;

    virtual bool operator==(const RenderObject& other) const = 0;

    bool operator!=(const RenderObject& other) const {
        return not(*this == other);
    }
};
