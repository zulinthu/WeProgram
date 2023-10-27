#include "QtGuiClassmm.h"
#include <QDebug>

QtGuiClassmm::QtGuiClassmm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QHBoxLayout* layout = new QHBoxLayout(this);
	QLabel* label = new QLabel("×æÁØ", this);
	QPushButton* btn = new QPushButton("¡­", this);
	layout->addWidget(label);
	layout->addWidget(btn);
	//connect(btn, &QPushButton::clicked, this, &QtGuiClassmm::addRightWidget1);
	qDebug() << "mm";
}
void QtGuiClassmm::addRightWidget1() {
	emit addRightWidget1Signal();
}

QtGuiClassmm::~QtGuiClassmm()
{
}
