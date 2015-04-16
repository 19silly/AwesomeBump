#ifndef GLIMAGEEDITOR_H
#define GLIMAGEEDITOR_H

/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLFunctions_4_0_Core>

#include "glwidgetbase.h"

#include <math.h>
#include <map>
#include "CommonObjects.h"
#include "formmaterialindicesmanager.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram);


//! [0]
class GLImage : public GLWidgetBase , protected QOpenGLFunctions_4_0_Core
{
    Q_OBJECT

public:
    GLImage(QWidget *parent = 0 );
    ~GLImage();
    void cleanup();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void setActiveImage(FBOImageProporties* ptr);
    FBOImageProporties* getActiveImage(){return activeImage;}
    void enableShadowRender(bool enable);
    void setConversionType(ConversionType conversionType);
    void updateCornersPosition(QVector2D dc1,QVector2D dc2,QVector2D dc3,QVector2D dc4);
    void render();

    FBOImageProporties* targetImageDiffuse;
    FBOImageProporties* targetImageNormal;
    FBOImageProporties* targetImageHeight;
    FBOImageProporties* targetImageSpecular;
    FBOImageProporties* targetImageOcclusion;
    FBOImageProporties* targetImageRoughness;
    FBOImageProporties* targetImageMetallic;

    FBOImageProporties* targetImageMaterial;
public slots:
    void resizeFBO(int width, int height);

    void resetView();
    void selectPerspectiveTransformMethod(int method);
    void selectUVManipulationMethod(UVManipulationMethods method);
    void updateCornersWeights(float w1, float w2, float w3, float w4);
    void selectSeamlessMode(SeamlessMode mode);
    void toggleColorPicking(bool toggle);
signals:
    void rendered();
    void readyGL();
    void colorPicked(QVector4D color);
//! [2]
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void relativeMouseMoveEvent(int dx, int dy, bool *wrapMouse, Qt::MouseButtons buttons);
    void wheelEvent(QWheelEvent *event);
    void updateMousePosition();
    void showEvent(QShowEvent* event);

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
public:
    void applyGaussFilter(QGLFramebufferObject* sourceFBO, QGLFramebufferObject *auxFBO,
                          QGLFramebufferObject* outputFBO, int no_iter, float w =0);
    void applyMaskedGaussFilter(QGLFramebufferObject* sourceFBO,
                                QGLFramebufferObject* maskFBO,
                                QGLFramebufferObject *auxFBO, QGLFramebufferObject *aux2FBO,
                                QGLFramebufferObject* outputFBO);

    void applyInverseColorFilter(QGLFramebufferObject* inputFBO,
                                 QGLFramebufferObject* outputFBO);


    void applyRemoveShadingFilter(QGLFramebufferObject* inputFBO,
                                   QGLFramebufferObject* aoMaskFBO, QGLFramebufferObject *refFBO,
                                   QGLFramebufferObject* outputFBO);

    void applyRemoveLowFreqFilter(QGLFramebufferObject* inputFBO,
                                  QGLFramebufferObject* auxFBO,
                                  QGLFramebufferObject* outputFBO);

    void applyNormalFilter(  QGLFramebufferObject* inputFBO,
                             QGLFramebufferObject* outputFBO);

    void applyNormalFilter(QGLFramebufferObject* inputFBO);

    void applyColorHueFilter(  QGLFramebufferObject* inputFBO,
                               QGLFramebufferObject* outputFBO);


    void applyPerspectiveTransformFilter(  QGLFramebufferObject* inputFBO,
                                           QGLFramebufferObject* outputFBO);



    void applyCompressedFormatFilter(QGLFramebufferObject* baseFBO,
                                     QGLFramebufferObject* alphaFBO,
                                     QGLFramebufferObject* outputFBO);

    void applyOverlayFilter( QGLFramebufferObject* layerAFBO,
                             QGLFramebufferObject* layerBFBO,
                             QGLFramebufferObject* outputFBO);
    void applySeamlessFilter(QGLFramebufferObject* inputFBO,
                             QGLFramebufferObject* outputFBO);
    void applySeamlessLinearFilter(QGLFramebufferObject* inputFBO,
                             QGLFramebufferObject* outputFBO);

    void applyDGaussiansFilter(QGLFramebufferObject* inputFBO,
                             QGLFramebufferObject *auxFBO,
                             QGLFramebufferObject* outputFBO, bool bUseSelectiveBlur = false);
    void applyContrastFilter(QGLFramebufferObject* inputFBO,
                             QGLFramebufferObject* outputFBO, bool bUseSelectiveBlur = false);
    void applySmallDetailsFilter(QGLFramebufferObject* inputFBO,
                                 QGLFramebufferObject *auxFBO,
                                 QGLFramebufferObject* outputFBO);
    void applyMediumDetailsFilter(QGLFramebufferObject* inputFBO,
                                          QGLFramebufferObject* auxFBO,
                                 QGLFramebufferObject* outputFBO);
    void applyGrayScaleFilter(QGLFramebufferObject* inputFBO,
                              QGLFramebufferObject* outputFBO);

    void applyInvertComponentsFilter(QGLFramebufferObject* inputFBO,
                                    QGLFramebufferObject* outputFBO);

    void applySharpenBlurFilter(QGLFramebufferObject* inputFBO,
                                QGLFramebufferObject *auxFBO,
                                QGLFramebufferObject* outputFBO);

    void applyNormalsStepFilter(QGLFramebufferObject* inputFBO,
                                QGLFramebufferObject* outputFBO);
    void applySobelToNormalFilter(QGLFramebufferObject* inputFBO,
                                  QGLFramebufferObject* outputFBO, BaseMapConvLevelProperties &convProp);

    void applyNormalExpansionFilter(QGLFramebufferObject* inputFBO,
                                  QGLFramebufferObject* outputFBO);

    void applyMixNormalLevels(GLuint level0,
                              GLuint level1,
                              GLuint level2,
                              GLuint level3,
                              QGLFramebufferObject* outputFBO);

    void applyCPUNormalizationFilter(QGLFramebufferObject* inputFBO,
                                  QGLFramebufferObject* outputFBO);



    void applyHeightToNormal(QGLFramebufferObject* inputFBO,
                             QGLFramebufferObject* outputFBO);

    void applyNormalToHeight(FBOImageProporties *image,
                             QGLFramebufferObject* normalFBO,
                             QGLFramebufferObject* heightFBO,
                             QGLFramebufferObject* outputFBO);

    void applyBaseMapConversion(QGLFramebufferObject* baseMapFBO,
                                QGLFramebufferObject *auxFBO,
                                QGLFramebufferObject* outputFBO, BaseMapConvLevelProperties &convProp);
    void applyPreSmoothFilter(QGLFramebufferObject* inputFBO,
                              QGLFramebufferObject *auxFBO,
                             QGLFramebufferObject* outputFBO, BaseMapConvLevelProperties &convProp);

    void applyOcclusionFilter(GLuint height_tex,
                              GLuint normal_tex,
                              QGLFramebufferObject* outputFBO);

    void applyHeightProcessingFilter( QGLFramebufferObject* inputFBO,
                                      QGLFramebufferObject* outputFBO,
                                      bool bUseSelectiveBlur = false);

    void applyCombineNormalHeightFilter(QGLFramebufferObject* normalFBO,
                                        QGLFramebufferObject *heightFBO,
                                        QGLFramebufferObject* outputFBO);

    void applyRoughnessFilter(QGLFramebufferObject* inputFBO,
                              QGLFramebufferObject *auxFBO,
                              QGLFramebufferObject* outputFBO);

    void applyRoughnessColorFilter(QGLFramebufferObject* inputFBO,
                                   QGLFramebufferObject* outputFBO);

    void copyFBO(QGLFramebufferObject* src,QGLFramebufferObject* dst);
    void copyTex2FBO(GLuint src_tex_id,QGLFramebufferObject* dst);

//! [3]
private:
    void makeScreenQuad();

    QOpenGLShaderProgram *program;
    FBOImageProporties* activeImage;
    QGLFramebufferObject* averageColorFBO; // small FBO used for calculation of average color
    QGLFramebufferObject* samplerFBO1; // FBO with size 1024x1024
    QGLFramebufferObject* samplerFBO2; // FBO with size 1024x1024 used for different processing
    // FBOs used in image processing
    QGLFramebufferObject* auxFBO1;
    QGLFramebufferObject* auxFBO2;
    QGLFramebufferObject* auxFBO3;
    QGLFramebufferObject* auxFBO4;

    QGLFramebufferObject* auxFBO1BMLevels[3]; // 2 times smaller. 4 and 8
    QGLFramebufferObject* auxFBO2BMLevels[3]; //
    QGLFramebufferObject* auxFBO0BMLevels[3]; //


    std::map<std::string,GLuint> subroutines;

    GLuint vbos[3];
    ConversionType conversionType;
    bool bShadowRender;
    bool bSkipProcessing;   // draw quad but skip all the processing step (using during mouse interaction)
    float windowRatio;      // window width-height ratio
    float fboRatio;         // active fbo width-height ratio

    // Image resize
    int resize_width;
    int resize_height;

    // Image translation and physical cursor position
    double xTranslation; // x position of the image in the window
    double yTranslation; // y position
    double cursorPhysicalXPosition; // physical cursor X position in window
    double cursorPhysicalYPosition;

    double zoom; // magnification of the image
    double orthographicProjHeight;
    double orthographicProjWidth;

    // perspective transformation
    QVector2D cornerPositions[4]; // position of four corner used to perform perspective transformation of quad
    QVector4D cornerWeights;
    int draggingCorner; // contains Id of current corner dragged or -1
    QCursor cornerCursors[4];
    int gui_perspective_mode; // choose proper interpolation method
    int gui_seamless_mode; // if 0 standard blending, if 1 mirror mode

    bool bToggleColorPicking;

    // uv manipulations method
    UVManipulationMethods uvManilupationMethod;
};


#endif // GLIMAGEEDITOR_H

