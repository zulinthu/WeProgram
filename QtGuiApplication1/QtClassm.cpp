#include "QtClassm.h"
#include <QLabel>
#include <QPushButton>

QtClass::QtClass(QWidget *parent)
	: QWidget(parent)
{
	QHBoxLayout* layout = new QHBoxLayout(this);
	QLabel* label = new QLabel("×æÁØ", this);
	QPushButton* btn = new QPushButton("¡­", this);
	layout->addWidget(label);
	layout->addWidget(btn);

}

QtClass::~QtClass()
{
}
