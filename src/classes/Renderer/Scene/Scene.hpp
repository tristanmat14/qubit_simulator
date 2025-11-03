
#pragma once
#include <vector>
#include <memory>
#include "RenderObject.hpp"
#include "Color.hpp"

class Scene : public RenderObject {
private:
    Color _c;
    std::vector<std::shared_ptr<RenderObject>> renderObjects;

public:
    Scene();
    explicit Scene(Color& c);

    // NOTE: difference between render and draw is that render is less abstracted
    // away from the GPU code, while render commands do the real rendering work.
    void render() const;
    void draw() const override;

    /**
     * Adds a renderObject shared ptr to the window object.
     * Does not add the renderObject if a geometrically equivalent renderObject is
     * already in the window.
     * @param renderObj - the renderObject to add to the window
     */
    void addRenderObject(std::shared_ptr<RenderObject> renderObj);

    /**
     * Removes a renderObj from the window object.
     * @param renderObj - the renderObject to remove from the window
     */
    void removeRenderObject(const std::shared_ptr<RenderObject>& renderObj);

    virtual ~Scene() = default;
};