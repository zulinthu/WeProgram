#ifndef QTCLASSMESSAGE_H
#define QTCLASSMESSAGE_H
#pragma once

#include<qpushbutton.h>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QAction>
#include<QDebug>
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QtWidgets/QWidget>
//#include "ui_QtClassMessage.h"

class QtClassMessage : public QWidget
{
	Q_OBJECT

public:
	QtClassMessage(QWidget *parent);
	~QtClassMessage();
public:
	//QtClassMessage(QWidget* parent = Q_NULLPTR);

private:
	//Ui::QtClassMessage ui;
};
#endif