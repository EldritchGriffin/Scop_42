#include <Object.hpp>

// FIXME this may not work because of always using the same VAO and VBO glEnableVertexAttribArray(*0*);
Object::Object(float vertices[])
{
    this->_vertices = vertices;
    // glGenVertexArrays(1, &this->_VAO);
    // glBindVertexArray(this->_VAO);
    glGenBuffers(1, &this->_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->_vertices), this->_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}

Object::~Object()
{
    // glDeleteVertexArrays(1, &this->_VAO);
    glDeleteBuffers(1, &this->_VBO);
}