#ifndef QTGUICLASSM_H
#define QTGUICLASSM_H
#pragma once
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <QWidget>
#include "ui_QtGuiClassm.h"

class QtGuiClassm : public QWidget
{
	Q_OBJECT

public:
	QtGuiClassm(QWidget *parent = Q_NULLPTR);
	~QtGuiClassm();

private:
	Ui::QtGuiClassm ui;
}
#endif QTGUICLASSM_H
