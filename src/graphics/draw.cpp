#include "draw.h"

Whiteboard::Whiteboard() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glLineWidth(3.0f);
}

Whiteboard::~Whiteboard() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Whiteboard::startStroke() {
    strokes.push_back(Stroke());
}

void Whiteboard::addPoint(float x, float y) {
    if (!strokes.empty()) {
        strokes.back().points.push_back(x);
        strokes.back().points.push_back(y);
    }
}

void Whiteboard::clear() {
    strokes.clear();
}

void Whiteboard::draw() {
    glBindVertexArray(VAO);

    for (const auto& stroke : strokes) {
        if (stroke.points.size() < 4) continue;

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, stroke.points.size() * sizeof(float), stroke.points.data(), GL_DYNAMIC_DRAW);

        glDrawArrays(GL_LINE_STRIP, 0, stroke.points.size() / 2);
    }
}