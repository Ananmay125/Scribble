#pragma once
#include <glad/glad.h>
#include <vector>

struct Stroke {
    std::vector<float> points;
};

class Whiteboard {
public:
    Whiteboard();
    ~Whiteboard();

    void startStroke();
    void addPoint(float x, float y);
    void clear();
    void draw();

private:
    std::vector<Stroke> strokes;
    unsigned int VAO, VBO;
};