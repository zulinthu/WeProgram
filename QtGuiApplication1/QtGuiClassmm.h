//#ifndef QTGUICLASSM_H
//#define QTGUICLASSM_H
#pragma once

#include "ui_QtGuiClassmm.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#pragma execution_character_set("utf-8")
class QtGuiClassmm : public QWidget
{
	Q_OBJECT

public:
	QtGuiClassmm(QWidget *parent = Q_NULLPTR);
	~QtGuiClassmm();
signals:
	void addRightWidget1Signal();




private:
	Ui::QtGuiClassmm ui;
private slots:
	void addRightWidget1();
};
//#endif
