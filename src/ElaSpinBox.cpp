#include "ElaSpinBox.h"

#include <QLineEdit>

#include "DeveloperComponents/ElaSpinBoxStyle.h"
#include "ElaApplication.h"
ElaSpinBox::ElaSpinBox(QWidget* parent)
    : QSpinBox(parent)
{
    setFixedSize(120, 30);
    setStyle(new ElaSpinBoxStyle(style()));
    lineEdit()->setAlignment(Qt::AlignCenter);
    lineEdit()->setStyleSheet("background-color:transparent");
    connect(eApp, &ElaApplication::themeModeChanged, this, [=](ElaApplicationType::ThemeMode themeMode) {
        QPalette palette;
        palette.setColor(QPalette::Base, Qt::transparent);
        palette.setColor(QPalette::Text, themeMode == ElaApplicationType::Light ? Qt::black : Qt::white);
        lineEdit()->setPalette(palette);
    });
}

ElaSpinBox::~ElaSpinBox()
{
}
