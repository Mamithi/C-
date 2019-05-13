#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QTextEdit;


class Window : public QWidget
{
Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;
};

#endif // WINDOW_H
