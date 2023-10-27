#pragma once

#include <QMainWindow>
#include "ui_QtGuiClass.h"
#include "QtGuiApplication1.h"
#include "QtGuiClassmm.h"
#include <qpoint.h>

class QtGuiClass : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();
private slots:
	void test();
	void addRightWidget();
//	void showMaximized();
	//QtGuiClassmm display();
protected:
	void mousePressEvent(QMouseEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
private:
	Ui::QtGuiClass ui;
	/*QtGuiApplication1* w;
	QtGuiClassmm* v;*/
	QtGuiClassmm* message;
	QtGuiApplication1* search;
	//int* i;
	//void mousePressEvent(QMouseEvent* event);
	//void mouseReleaseEvent(QMouseEvent* event);
	//void mouseMoveEvent(QMouseEvent* event);
	QPoint m_dragPosition;
	QPoint windowTopLeftPoint;
	QPoint mouseStartPoint;
	bool isMove = false;
	
};
