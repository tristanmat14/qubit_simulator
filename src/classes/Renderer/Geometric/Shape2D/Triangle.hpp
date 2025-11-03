#pragma once
#include <array>
#include "glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shape2D.hpp"

class Triangle {
private:
    glm::vec3 _position;
    glm::vec3 _normal;
    float _degrees;
    TriangleMesh _mesh;
public:
    explicit Triangle(
        const glm::vec3& position, const glm::vec3& normal, const float degrees, const TriangleMesh& mesh
    ) { 
        _position = glm::vec3(position);
        _normal = glm::vec3(normal);
        _degrees = degrees;
        _mesh = mesh;
    }

    void rotateAroundNormal(float angleDeg) {
        float angle = glm::radians(angleDeg);

        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), angle, getNormal());

        for (auto& v : _vertices) {
            v = glm::vec3(rotation * glm::vec4(v, 1.0f));
        }

        updateVertexBuffers();
    }

    void draw() const override {
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::rotate(transform, glm::radians(_degrees), normal);
        transform = glm::translate(transform, position);
        mesh->render(transform);
    }
};
