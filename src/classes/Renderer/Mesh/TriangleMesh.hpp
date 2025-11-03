#pragma once
#include <array>
#include "glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class TriangleMesh {
private:
    // temp shader variable - refactor out
    GLuint shaderProgram;

    std::array<glm::vec3, 3> vertices = {
        glm::vec3{0.0f,  0.5f, 0.0f}, // top
        glm::vec3{-0.5f, -0.5f, 0.0f}, // left
        glm::vec3{0.5f, -0.5f, 0.0f}  // right
    };
    GLuint vao, vbo;

    void updateVertexBuffers() {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

public:
    // Temperorary constructor for providing a shader program
    TriangleMesh(GLuint shader) : shaderProgram(shader) {}

    void render(const glm::mat4 transform) const {
        glUseProgram(shaderProgram);
        unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
    }

    ~TriangleMesh() {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
    }
};
