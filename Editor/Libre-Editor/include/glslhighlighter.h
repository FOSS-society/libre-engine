#ifndef GLSLHIGHLIGHTER_H
#define GLSLHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class GLSLHighlighter : public QSyntaxHighlighter
    {
    Q_OBJECT

        private:

        struct HighlightingRule
        {
            QRegExp pattern;
            QTextCharFormat format;
        };
        QVector<HighlightingRule> highlightingRules;

        QRegExp commentStartExpression;
        QRegExp commentEndExpression;

        QTextCharFormat keywordFormat;
        QTextCharFormat classFormat;
        QTextCharFormat singleLineCommentFormat;
        QTextCharFormat multiLineCommentFormat;
        QTextCharFormat quotationFormat;
        QTextCharFormat functionFormat;
    public:
        explicit GLSLHighlighter(QObject *parent = 0);
        void highlightBlock(const QString &text);


    signals:

    public slots:


        // QSyntaxHighlighter interface
    protected:

};

#endif // GLSLHIGHLIGHTER_H
