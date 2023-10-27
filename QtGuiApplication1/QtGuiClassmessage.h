#pragma once

#include <QWidget>
#include "ui_QtGuiClassmessage.h"
#pragma execution_character_set("utf-8")

class QtGuiClassmessage : public QWidget
{
	Q_OBJECT

public:
	QtGuiClassmessage(QWidget *parent = Q_NULLPTR);
	~QtGuiClassmessage();

private:
	Ui::QtGuiClassmessage ui;
};
