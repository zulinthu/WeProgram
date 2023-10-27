#include "QtClassMessage.h"
#include <QLabel>
#include <QPushButton>
//#include <QHBoxLayout>

QtClassMessage::QtClassMessage(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	QHBoxLayout* layout = new QHBoxLayout( this);
	QLabel* label = new QLabel("×æÁØ", this);
	QPushButton* btn = new QPushButton("¡­", this);
	layout->addWidget(label);
	layout->addWidget(btn);


}

QtClassMessage::~QtClassMessage()
{

}
