attribute vec4 Vertex;
attribute vec4 MultiTexCoord0;
uniform mat4 ModelViewProjectionMatrix;
varying vec4 TexCoord0;

void main(void)
{
    gl_Position = ModelViewProjectionMatrix * Vertex;
    TexCoord0 = MultiTexCoord0;
}
