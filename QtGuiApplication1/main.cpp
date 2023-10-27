#include "QtGuiApplication1.h"
#include "QtGuiClass.h"
#include "QtGuiClassmm.h"
#include <QtWidgets/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApplication1 n;
	QtGuiClass m;
	QtGuiClass tt;
	tt.show();
	QtGuiClassmm v;
	//v.show();
	qDebug() << "1";
	//QtClassm v;
	//v.show();
	m.setWindowTitle("weChat");
	m.setCentralWidget(&n);

	//在右侧显示一个widget
	/*QHBoxLayout* mainlayout = qobject_cast<QHBoxLayout*>(w.layout());
	mainlayout->addWidget(&v);*/
	//m.show();
	return a.exec();
}
