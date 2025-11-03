#pragma once
#include <vector>
#include <memory>
#include "Scene.hpp"
#include "Debug.h"
#include "Color.hpp"

Scene::Scene() : _c() {}

Scene::Scene(Color& c) : _c(c) {}

void Scene::render() const {
    DEBUG("Render window");
   
    // render scene
    const glm::vec4& color = c.getColor();
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Render children
    for (const auto& r : renderObjects) {
        r->draw();
    }

    // Swap buffers & poll events
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}

void Scene::draw() const { 
    DEBUG("Draw window");
    for (const auto& r : renderObjects) {
        r->draw();
    }
}

void Scene::addRenderObject(std::shared_ptr<RenderObject> renderObj) {
        for (const auto& existing : renderObjects) {
            if (*existing == *renderObj) return;
        }
        renderObjects.push_back(renderObj);
    }

void Scene::removeRenderObject(const std::shared_ptr<RenderObject>& renderObj) {
    renderObjects.erase(
        std::remove(renderObjects.begin(), renderObjects.end(), renderObj),
        renderObjects.end()
    );
}
