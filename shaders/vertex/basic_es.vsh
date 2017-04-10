attribute highp vec4 Vertex;
attribute highp vec4 MultiTexCoord0;
uniform highp mat4 ModelViewProjectionMatrix;
varying highp vec4 TexCoord0;

void main(void)
{
    gl_Position = ModelViewProjectionMatrix * Vertex;
    TexCoord0 = MultiTexCoord0;
}
