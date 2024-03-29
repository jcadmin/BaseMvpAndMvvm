//
// Created by 49242 on 2022/11/3.
//
#include "TriangleSample.h"
#include "GLUtils.h"
#include "LogUtil.h"

TriangleSample::TriangleSample() {

}

TriangleSample::~TriangleSample() {
    if (m_ProgramObj) {
        glDeleteProgram(m_ProgramObj);
    }
}

void TriangleSample::Init() {
    char vShaderStr[] =
            "#version 300 es                          \n"
            "layout(location = 0 ) in vec4 vPosition; \n"
            "void main()                              \n"
            "{                                        \n"
            "gl_Position = vPosition;                  \n"
            "}                                        \n";

    char fShaderStr[] =
            "#version 300 es                             \n"
            "precision mediump float;                    \n"
            "out vec4 fragColor;                         \n"
            "void main()                                 \n"
            "{                                           \n"
            " fragColor = vec4 (1.0, 0.0 , 0.0 ,1.0 );   \n"
            "}                                         \n";

    m_ProgramObj = GLUtils::CreateProgram(vShaderStr, fShaderStr, m_VertexShader, m_FragmentShader);
}

void TriangleSample::Draw() {
    LOGCATE("TriangleSample::Draw(");
    GLfloat vVertices[] = {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f
    };
    if (m_ProgramObj == 0) {
        LOGCATE("m_ProgramObj is null");
        return;
    }
    glUseProgram(m_ProgramObj);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}