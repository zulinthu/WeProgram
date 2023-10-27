#include "QtGuiClassm.h"
//#include <QHBoxLayout>
//#include <QLabel>
//#include <QPushButton>


QtGuiClass::QtGuiClassm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QHBoxLayout* layout = new QHBoxLayout(this);
	QLabel* label = new QLabel("×æÁØ", this);
	QPushButton* btn = new QPushButton("¡­", this);
	layout->addWidget(label);
	layout->addWidget(btn);

}

QtGuiClass::~QtGuiClassm()
{
}
