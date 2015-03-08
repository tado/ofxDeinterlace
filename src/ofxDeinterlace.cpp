//
//  ofxDeinterlace.cpp
//  example
//
//  Created by Atsushi Tadokoro on 3/8/15.
//
//
#include "ofxDeinterlace.h"

ofxDeinterlace::ofxDeinterlace(ofTexture _texture){
    tex0 = _texture;
    
    width = tex0.getWidth();
    height = tex0.getHeight();
    
    frag = STRINGIFY
    (
     uniform sampler2DRect tex0;
     varying vec2 texcoord0;
     varying vec2 texdim0;
     
     void main (void){
         float isodd = mod(texcoord0.y, 2.0);
         vec4 result;
         if(bool(isodd)){
             vec4 evenfield = texture2DRect(tex0, vec2(texcoord0.x, texcoord0.y + 1.0));
             vec4 oddfield = texture2DRect(tex0, texcoord0);
             result = mix(evenfield, oddfield, 0.5);
         } else {
             vec4 evenfield = texture2DRect(tex0, texcoord0);
             vec4 oddfield = texture2DRect(tex0, vec2(texcoord0.x, texcoord0.y - 1.0));
             result = mix(evenfield, oddfield, 0.5);
         }
         gl_FragColor = result;
     }
     );
    
    vert = STRINGIFY
    (
     varying vec2 texcoord0;
     varying vec2 texdim0;
     
     void main(){
         gl_Position = ftransform();
         texcoord0 = vec2(gl_TextureMatrix[0] * gl_MultiTexCoord0);
         texdim0 = vec2 (abs(gl_TextureMatrix[0][0] [0]),abs(gl_TextureMatrix[0][1][1]));
     }
     );
    
    if (frag.empty() == false) {
        deinterlaceShader.setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
    }
    if (vert.empty() == false) {
        deinterlaceShader.setupShaderFromSource(GL_VERTEX_SHADER, vert);
    }
    
    deinterlaceShader.linkProgram();
    deinterlaceShader.begin();
    deinterlaceShader.setUniformTexture("tex0", tex0, 0);
    deinterlaceShader.end();
}

void ofxDeinterlace::draw(){
    deinterlaceShader.begin();
    glActiveTexture(GL_TEXTURE0_ARB);
    tex0.bind();
    
    glBegin(GL_QUADS);
    
    glMultiTexCoord2d(GL_TEXTURE0_ARB, 0, 0);
    glVertex2f(0, 0);
    
    glMultiTexCoord2d(GL_TEXTURE0_ARB, tex0.getWidth(), 0);
    glVertex2f(width, 0);
    
    glMultiTexCoord2d(GL_TEXTURE0_ARB, tex0.getWidth(), tex0.getHeight());
    glVertex2f( width, height);
    
    glMultiTexCoord2d(GL_TEXTURE0_ARB, 0, tex0.getHeight());
    glVertex2f(0, height );
    
    glEnd();
    tex0.unbind();
    deinterlaceShader.end();
}
