#include "include/glslhighlighter.h"





GLSLHighlighter::GLSLHighlighter(QObject *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

        keywordFormat.setForeground(Qt::darkBlue);
        keywordFormat.setFontWeight(QFont::Bold);
        QStringList keywordPatterns;
        keywordPatterns << "\\attribute\\b" << "\\const\\b" << "\\uniform\\b"
                        << "\\varying\\b" << "\\layout\\b" << "\\centroid\\b"
                        << "\\flat\\b" <<    "\\smooth\\b" << "\\noperspective\\b"
                        << "\\patch\\b" <<    "\\sample\\b" << "\\break\\b"
                        << "\\continue\\b" <<   "\\do\\b" <<   "\\for\\b"
                        << "\\while\\b" <<    "\\switch\\b" << "\\case\\b"
                        << "\\default\\b" << "\\if\\b" << "\\else\\b"
                        << "\\subroutine\\b" << "\\in\\b" << "\\out\\b"
                        << "\\inout\\b" << "\\float\\b" <<   "\\double\\b"
                        << "\\int\\b" <<   "\\void\\b" << "\\bool\\b"
                        << "\\true\\b" <<  "\\false\\b" << "\\invariant\\b"
                        << "\\discard\\b" <<   "\\return\\b" << "\\mat2\\b"
                        <<  "\\mat3\\b" <<  "\\mat4\\b" <<  "\\dmat2\\b"
                        <<  "\\dmat3\\b" <<  "\\dmat4\\b" << "\\mat2x2\\b"
                        <<  "\\mat2x3\\b" <<  "\\mat2x4\\b" <<    "\\dmat2x2\\b"
                        <<   "\\dmat2x3\\b" <<   "\\dmat2x4\\b" << "\\mat3x2\\b"
                        <<  "\\mat3x3\\b" <<  "\\mat3x4\\b" <<    "\\dmat3x2\\b"
                        <<   "\\dmat3x3\\b" <<   "\\dmat3x4\\b" << "\\mat4x2\\b"
                        <<  "\\mat4x3\\b" <<  "\\mat4x4\\b" <<    "\\dmat4x2\\b"
                        <<   "\\dmat4x3\\b" <<   "\\dmat4x4\\b" << "\\vec2\\b"
                        <<   "\\vec3\\b" <<  "\\vec4\\b" <<    "\\ivec2\\b"
                        <<   "\\ivec3\\b" <<   "\\ivec4\\b" <<    "\\bvec2\\b"
                        <<   "\\bvec3\\b" <<   "\\bvec4\\b" <<    "\\dvec2\\b"
                        <<    "\\dvec3\\b" <<    "\\dvec4\\b" << "\\uint\\b"
                        <<    "\\uvec2\\b" <<    "\\uvec3\\b" << "\\uvec4\\b"
                        << "\\lowp\\b" <<    "\\mediump\\b" <<    "\\highp\\b"
                        <<  "\\precision\\b" << "\\sampler1D\\b" << "\\sampler2D\\b"
                        <<   "\\sampler3D\\b" << "\\samplerCube\\b" << "\\sampler1DShadow\\b"
                        <<   "\\sampler2DShadow\\b" <<    "\\samplerCubeShadow\\b" << "\\sampler1DArray\\b"
                        <<   "\\sampler2DArray\\b" << "\\sampler1DArrayShadow\\b" <<   "\\sampler2DArrayShadow\\b"
                        << "\\isampler1D\\b" <<   "\\isampler2D\\b" <<   "\\isampler3D\\b" <<   "\\isamplerCube\\b"
                        << "\\isampler1DArray\\b" << "\\isampler2DArray\\b" << "\\usampler1D\\b"
                        <<  "\\usampler2D\\b" <<   "\\usampler3D\\b" <<   "\\usamplerCube\\b"
                        << "\\usampler1DArray\\b" <<   "\\usampler2DArray\\b" << "\\sampler2DRect\\b"
                        << "\\sampler2DRectShadow\\b" <<    "\\isampler2DRect\\b" <<    "\\usampler2DRect\\b"
                        << "\\samplerBuffer\\b" <<    "\\isamplerBuffer\\b" <<    "\\usamplerBuffer\\b"
                        << "sampler2DMS\\b" <<    "\\isampler2DMS\\b" <<    "\\usampler2DMS\\b"
                        << "sampler2DMSArray\\b" <<    "\\isampler2DMSArray\\b" <<    "\\usampler2DMSArray\\b"
                        << "\\samplerCubeArray\\b" <<  "\\samplerCubeArrayShadow\\b" <<   "\\isamplerCubeArray\\b"
                        <<   "\\usamplerCubeArray\\b" <<"\\struct\\b" ;


        foreach (const QString &pattern, keywordPatterns) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
}
        classFormat.setFontWeight(QFont::Bold);
            classFormat.setForeground(Qt::darkCyan);
            rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
            rule.format = classFormat;
            highlightingRules.append(rule);

            singleLineCommentFormat.setForeground(Qt::green);
            rule.pattern = QRegExp("//[^\n]*");
            rule.format = singleLineCommentFormat;
            highlightingRules.append(rule);

            multiLineCommentFormat.setForeground(Qt::cyan);

            quotationFormat.setForeground(Qt::darkGreen);
            rule.pattern = QRegExp("\".*\"");
            rule.format = quotationFormat;
            highlightingRules.append(rule);

            functionFormat.setFontItalic(true);
            functionFormat.setForeground(Qt::yellow);
            rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
            rule.format = functionFormat;
            highlightingRules.append(rule);

            commentStartExpression = QRegExp("/\\*");
            commentEndExpression = QRegExp("\\*/");
}

void GLSLHighlighter::highlightBlock(const QString &text)
    {
        foreach (const HighlightingRule &rule, highlightingRules) {
            QRegExp expression(rule.pattern);
            int index = expression.indexIn(text);
            while (index >= 0) {
                int length = expression.matchedLength();
                setFormat(index, length, rule.format);
                index = expression.indexIn(text, index + length);
            }
        }
        setCurrentBlockState(0);

        int startIndex = 0;
        if (previousBlockState() != 1)
            startIndex = commentStartExpression.indexIn(text);

        while (startIndex >= 0) {
            int endIndex = commentEndExpression.indexIn(text, startIndex);
            int commentLength;
            if (endIndex == -1) {
                setCurrentBlockState(1);
                commentLength = text.length() - startIndex;
            } else {
                commentLength = endIndex - startIndex
                                + commentEndExpression.matchedLength();
            }
            setFormat(startIndex, commentLength, multiLineCommentFormat);
            startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
        }
}

