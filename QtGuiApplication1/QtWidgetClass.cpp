#include "QtWidgetClass.h"
#include "QDebug"

QtClass::QtClass(QWidget *parent)
	: QWidget(parent)
{
	qDebug() << "1";
}

QtClass::~QtClass()
{
}
