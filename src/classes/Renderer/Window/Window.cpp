#pragma once
#include <vector>
#include <memory>
#include <Window.h>
#include <Debug.h>

Window::Window() : _c() {}

Window::Window(Color& c) : _c(c) {}

void Window::draw() const { 
    DEBUG("Draw window");
    // TODO: Draw logic for the window
    for (const auto& r : renderObjects) {
        r->draw();
    }
}

void Window::addRenderObject(std::shared_ptr<RenderObject> renderObj) {
        for (const auto& existing : renderObjects) {
            if (*existing == *renderObj) return;
        }
        renderObjects.push_back(renderObj);
    }

void Window::removeRenderObject(const std::shared_ptr<RenderObject>& renderObj) {
    renderObjects.erase(
        std::remove(renderObjects.begin(), renderObjects.end(), renderObj),
        renderObjects.end()
    );
}
