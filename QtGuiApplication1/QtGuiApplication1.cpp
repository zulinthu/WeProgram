#include "QtGuiApplication1.h"
#include<qpushbutton.h>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QAction>
#include<QDebug>
#pragma execution_character_set("utf-8")
//��������

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QHBoxLayout* layout = new QHBoxLayout(this);
	QPushButton* btn = new QPushButton("+", this);
	QLineEdit* source = new QLineEdit(this);
	layout->addWidget(source);
	layout->addWidget(btn);
	//����������ͼƬ
	/*QPixmap pixmap;
	pixmap.load("");
	QString image = QString().arg(pixmap);*/
	//source->setStyleSheet("QLineEdit{background-image:url(':/wechat/QtGuiApplication1/resource/search.png');padding-left:30px;}");
	QAction* action = new QAction(this);
	action->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/search.png"));//��ʱ������
	source->addAction(action, QLineEdit::LeadingPosition);
	source->setPlaceholderText("search");
	source->setStyleSheet("QLineEdit{color:black}");
	qDebug() << "connect established";
	/*connect(btn, &QPushButton::clicked, [=]() {
		qDebug() << "2";
		});*/

}
