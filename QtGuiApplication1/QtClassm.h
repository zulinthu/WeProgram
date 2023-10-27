#ifndef QTCLASSM_H
#define QTCLASSM_H
#pragma once

#include<qpushbutton.h>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QAction>
#include<QDebug>
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>

#include <QWidget>

class QtClass : public QWidget
{
	Q_OBJECT

public:
	QtClass(QWidget *parent);
	~QtClass();
};
#endif
