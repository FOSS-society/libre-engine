uniform sampler2D Texture0;
varying highp vec4 TexCoord0;

void main(void)
{
    gl_FragColor = texture2D(Texture0, TexCoord0.st);
}
