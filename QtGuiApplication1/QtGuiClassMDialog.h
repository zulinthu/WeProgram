#pragma once

#include <QWidget>
#include "ui_QtGuiClassMDialog.h"

class QtGuiClassMDialog : public QWidget
{
	Q_OBJECT

public:
	QtGuiClassMDialog(QWidget *parent = Q_NULLPTR);
	~QtGuiClassMDialog();

private:
	Ui::QtGuiClassMDialog ui;
};
