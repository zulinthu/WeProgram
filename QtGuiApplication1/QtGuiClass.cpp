
#include "QtGuiClass.h"
#include <qtoolbar.h>
#include <QDebug>
#include <QIcon>
#include <QMenu>
#include <QMessageBox>
#include <QMainWindow>
#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>
#include <QPoint>
#include <QLabel>
#include <QCursor>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidgetAction>
#include <QSplitter>
#include <QTreeView>

#include "QtGuiClassmm.h"//一个widget
#include "QtGuiApplication1.h"//另一个widget

#pragma execution_character_set("utf-8")
//mainwindow中工具栏

QtGuiClass::QtGuiClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QToolBar* toolbar = new QToolBar("工具栏",this);
	addToolBar(Qt::LeftToolBarArea,toolbar);//左侧显示工具栏的按钮
	QAction* action = new QAction("帅b头像", this);
	toolbar->addAction(action);
	QString what = "test";
	connect(action, &QAction::triggered, [what]() {qDebug() << what; });
			/*[&]() {
		qDebug() << "you want execute what?" << endl;
		});*/
	qDebug() << "connect established";
	//显示头像
	QAction* head = new QAction("qpushbutton",this);
	head->setIcon(QIcon("F:/wechat/QtGuiApplication1/Debug/bitmap1.bmp"));
	toolbar->addAction(head);
	//connect(head, &QAction::triggered,this,&QtGuiClass::test());
	//connect(head, &QAction::triggered, [this]() {QMessageBox::information(this, "Title", "Message"); });//显示弹窗
	//在点击头像处显示弹窗
	//QAction* headimage = new QAction(this)
	//在头像点击时显示窗口
	QMenu* menu = new QMenu("myMenu",this);
	QWidget* menuwidget = new QWidget(this);
	QVBoxLayout* layout = new QVBoxLayout(menuwidget);
	
	
	QPushButton* btn1 = new QPushButton(this);
	QPushButton* btn2 = new QPushButton("发消息",this);
	
	btn1->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/search.png"));
	QLabel* label = new QLabel("mm",this);
	layout->addWidget(label);
	layout->addWidget(btn1);
	layout->addWidget(btn2);
	//在mainwindow中点击按钮在已经有的widget右侧添加一个widget
	//w = new QtGuiApplication1(this);//第一个widget
	//QtGuiClassmm* v = new QtGuiClassmm(this);//已经声明写过的类可以建立实例对象
	/*QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(w);
	centralWidget()->setLayout(mainLayout);*/
	//connect(v, &QtGuiClassmm::addRightWidget1Signal, this, &QtGuiClass::addRightWidget);
	//connect(btn2, &QPushButton::clicked, this, &QtGuiClass::addRightWidget);
	//mainLayout->addWidget(v);
	
	//第二种尝试
	//QSplitter* splitter = new QSplitter(this);
	//splitter->setOrientation(Qt::Horizontal);
	//setCentralWidget(splitter);
	//QTreeView* treeView = new QTreeView(splitter);
	//splitter->addWidget(treeView);
	//QWidget rightWidget;//= new QWidget(splitter);
	//QVBoxLayout* rightLayout = new QVBoxLayout(&rightWidget);
	//rightWidget.setLayout(rightLayout);
	//splitter->addWidget(&rightWidget);
	//QPushButton* button = new QPushButton("show/hide", this);

	//connect(button, &QPushButton::clicked, [&rightWidget]() {
	//	rightWidget.setVisible(!rightWidget.isVisible());
	//	});
	//addToolBar("toolbar")->addWidget(button);
	  // 创建QSplitter控件
	//QtGuiApplication1 tt;
	//QSplitter* splitter = new QSplitter(this);
	//splitter->setOrientation(Qt::Horizontal);
	//splitter->addWidget(&tt);
	//setCentralWidget(splitter);

	//// 创建左侧控件
	//QTreeView* treeView = new QTreeView(splitter);
	//splitter->addWidget(treeView);

	//// 创建右侧控件
	//QWidget* rightWidget = new QWidget(splitter);
	//QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
	////rightWidget->setLayout(rightLayout);
	//tt.setLayout(rightLayout);
	////splitter->addWidget(rightWidget);
	//splitter->addWidget(&tt);

	//// 创建按钮并添加到主窗口
	//QPushButton* button = new QPushButton("Show/Hide", this);
	//connect(button, &QPushButton::clicked, [rightWidget]() {
	//	rightWidget->setVisible(!rightWidget->isVisible());
	//	
	//	});
	///*connect(button, &QPushButton::clicked, [&tt]() {
	//	tt.setVisible(!tt.isVisible());
	//	
	//	});*/
	//addToolBar("toolbar")->addWidget(button);

	//给按钮2添加发消息的连接
	/*connect(btn2, &QPushButton::clicked, [this]() {
		QtGuiApplication1 w;
		QtGuiClassmm v;
		QHBoxLayout* mainlayout = qobject_cast<QHBoxLayout*>(w.layout());
		mainlayout->addWidget(&v);
		});*/
	QWidgetAction* action1 = new QWidgetAction(menu);
	action1->setDefaultWidget(menuwidget);

	menu->addAction(action1);

	menu->addAction("option 1");
	menu->addAction("option 2");
	menu->addAction("option 3");
	/*connect(head, &QAction::triggered, [this,toolbar, head, menu]() {
		QWidget* widget = toolbar->widgetForAction(head);
		if (widget) {
			QPoint pos = widget->geometry().bottomLeft();
			pos.setY(pos.y() + widget->geometry().height());
			menu->exec(widget->mapToGlobal(pos));
		}
		});*/
	//在鼠标当前位置显示弹窗
	QPoint mousepos = QCursor::pos();
	QPoint localPos = mapFromGlobal(mousepos);
	qDebug() << mousepos << "\t" << localPos;
	connect(head, &QAction::triggered, [this, localPos, menu]() {
		//menu->exec(mapToGlobal(localPos));
		menu->exec(localPos);
		});
	//显示其他widget.cpp内容
	message = new QtGuiClassmm(this);
	search = new QtGuiApplication1(this);
	message->hide();
	/*this->setCentralWidget(search);
	this->show();*/

	//显示右侧
	//用按钮
	
	/*QHBoxLayout* right = new QHBoxLayout(this);
	QWidget* centralWidget = new QWidget(this);
		centralWidget->setLayout(right);
		right->addWidget(search);
		setCentralWidget(search);//这里设置初始显示的之间窗口
		//search->show();
		this->show(); //显示当前mainwindow窗口
		//centralWidget
	connect(btn2, &QPushButton::clicked, [=]() {//按钮点击之后更改显示的画面
		qDebug() << "2";
		message->show();
		search->show();
		right->addWidget(search);
		right->addWidget(message);
		
		
		setCentralWidget(centralWidget);
		this->show();//显示当前mainwindow窗口
		//centralWidget->show();
		qDebug() << "1";
		});*/
	//在两个layout之间显示竖线
	QHBoxLayout* right = new QHBoxLayout(this);
	QWidget* centralWidget = new QWidget(this);
	QFrame* line = new QFrame(this);//设置竖线
	line->setFrameShape(QFrame::VLine);
	line->setFrameShadow(QFrame::Sunken);
	line->hide();
	centralWidget->setLayout(right);
	right->addWidget(search);
	setCentralWidget(search);//这里设置初始显示的之间窗口
	//search->show();
	this->show(); //显示当前mainwindow窗口
	//centralWidget
	connect(btn2, &QPushButton::clicked, [=]() {//按钮点击之后更改显示的画面
		qDebug() << "2";
		message->show();
		search->show();
		line->show();
		right->addWidget(search);
		right->addWidget(line);
		right->addWidget(message);
		right->setAlignment(line, Qt::AlignHCenter);
		right->setStretchFactor(message, 1);
		right->setStretchFactor(search, 1);
		right->setStretchFactor(line, 0);

		//centralWidget->setLayout(right);//把层添加到之间画面
		setCentralWidget(centralWidget);
		this->show();//显示当前mainwindow窗口
		//centralWidget->show();
		qDebug() << "1";
		});



	/*message->hide();
	
	connect(btn2, &QPushButton::clicked, [=]() {
		message->show();
		});*/
	//在窗口右上角三控件
	QToolBar* toolBartriple = new QToolBar(this);
	QHBoxLayout* rlayout = new QHBoxLayout(this);
	addToolBar(Qt::TopToolBarArea, toolBartriple);
	QAction* zoomOutAction = new QAction("Zoom Out",this);
	QAction* zoomInAction = new QAction("Zoom In",this);
	QAction* zoomCloseAction = new QAction("Zoom Close",this);
	//rlayout -> addAction(zoomOutAction);
	zoomOutAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/out.png"));
	
		toolBartriple->addAction(zoomOutAction);
		connect(zoomOutAction, &QAction::triggered, this, &QtGuiClass::showMinimized);
	zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/init.png"));
		toolBartriple->addAction(zoomInAction);
		//connect(zoomInAction, &QAction::triggered, this, &QtGuiClass::showMaximized);
		//使用拉姆达表达式构造
		//i = new int(0);
		/*int j = 0;
		bool isWindowMaximized = this->isMaximized();
		connect(zoomInAction, &QAction::triggered, [this,zoomInAction,&j,isWindowMaximized]() {
			
			if (j % 2) {//i是奇数次，因为初始值为0，则这里应该缩略
				zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/half.png"));
				
				qDebug() << j;
			}
			else {
				
			
  zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/init.png")) ;
			showMaximized();
			qDebug() << j<<"m";
			}
			j++;
			
			});*/
		//使用bool来给到if
		bool j = false;
		bool isWindowMaximized = this->isMaximized();//初始是false
		qDebug() << isWindowMaximized<<"?";
		connect(zoomInAction, &QAction::triggered, [this, zoomInAction, &j, &isWindowMaximized]() {

			if (isWindowMaximized) {//初始是放大图标，点击之后j=true
				zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/init.png"));
				showNormal();
				qDebug() << j;
				j = false;
				isWindowMaximized = this->isMaximized();
			}
			else {//false执行


				zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/half.png"));
				showMaximized();
				qDebug() << j << "m";
				isWindowMaximized = true;
			}
			

			});
	zoomCloseAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/close.png"));
		toolBartriple->addAction(zoomCloseAction);
		connect(zoomCloseAction, &QAction::triggered, this, &QtGuiClass::close);
//action右移
		QWidget* spacer = new QWidget();
		spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
		toolBartriple->insertWidget(zoomOutAction, spacer);
		//addToolBar
//替换窗口原有的放大缩小图标
		QWidget* titleBarWidget = new QWidget(this);
		titleBarWidget->setObjectName("TitleBarWidget");
		QList<QWidget*>titleBarButtons = findChildren<QWidget*>("qt_titlebarbutton");
		for (QWidget* button : titleBarButtons) {
			QStyle* style = button->style();
			if (style->inherits("QWindowsStyle")) {
				QIcon maximizeIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/close.png");
				style->standardIcon(QStyle::SP_TitleBarMaxButton, nullptr, button).swap(maximizeIcon);
			}
		}
		setWindowFlags(Qt::FramelessWindowHint);
		//titleBarWidget->setAlignment(Qt::AlignRight);
		right->setMenuBar(titleBarWidget);
		//加入缩略图thumbnail
//移动窗口
		//setWindowFlags(windowFlags() | Qt::Window);
		setMouseTracking(true);

}
//重写鼠标移动函数
/*void QtGuiClass::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		m_dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}
void QtGuiClass::mouseMoveEvent(QMouseEvent* event) {
	if (event->button() & Qt::LeftButton) {
		move(event->globalPos() - m_dragPosition);
		event->accept();
	}
}
void QtGuiClass::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		m_dragPosition = QPoint();
		event->accept();
	}
}*/
//第二种重写移动函数
void QtGuiClass::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		isMove = true;
		mouseStartPoint = event->globalPos();
		windowTopLeftPoint = this->frameGeometry().topLeft();
	}
}
void QtGuiClass::mouseMoveEvent(QMouseEvent* event) {
	if (isMove) {
		QPoint distance = event->globalPos() - mouseStartPoint;
		this->move(windowTopLeftPoint + distance);
	}
}
void QtGuiClass::mouseReleaseEvent(QMouseEvent* event) {
	isMove = false;
}



//重写showmaximized（）函数
//void QtGuiClass::showMaximized() {
//
//	QtGuiClass::showMaximized();
//}
void QtGuiClass::addRightWidget() {
	// v = new QtGuiClassmm(this);
		//QHBoxLayout * rightLayout = new QHBoxLayout(w);//注意这里要声明全局变量才可以直接这里引用
		//rightLayout->addWidget(v);
}






void QtGuiClass::test() {
	qDebug() << "1";
}

QtGuiClass::~QtGuiClass()
{
}
