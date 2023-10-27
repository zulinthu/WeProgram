
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

#include "QtGuiClassmm.h"//һ��widget
#include "QtGuiApplication1.h"//��һ��widget

#pragma execution_character_set("utf-8")
//mainwindow�й�����

QtGuiClass::QtGuiClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QToolBar* toolbar = new QToolBar("������",this);
	addToolBar(Qt::LeftToolBarArea,toolbar);//�����ʾ�������İ�ť
	QAction* action = new QAction("˧bͷ��", this);
	toolbar->addAction(action);
	QString what = "test";
	connect(action, &QAction::triggered, [what]() {qDebug() << what; });
			/*[&]() {
		qDebug() << "you want execute what?" << endl;
		});*/
	qDebug() << "connect established";
	//��ʾͷ��
	QAction* head = new QAction("qpushbutton",this);
	head->setIcon(QIcon("F:/wechat/QtGuiApplication1/Debug/bitmap1.bmp"));
	toolbar->addAction(head);
	//connect(head, &QAction::triggered,this,&QtGuiClass::test());
	//connect(head, &QAction::triggered, [this]() {QMessageBox::information(this, "Title", "Message"); });//��ʾ����
	//�ڵ��ͷ����ʾ����
	//QAction* headimage = new QAction(this)
	//��ͷ����ʱ��ʾ����
	QMenu* menu = new QMenu("myMenu",this);
	QWidget* menuwidget = new QWidget(this);
	QVBoxLayout* layout = new QVBoxLayout(menuwidget);
	
	
	QPushButton* btn1 = new QPushButton(this);
	QPushButton* btn2 = new QPushButton("����Ϣ",this);
	
	btn1->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/search.png"));
	QLabel* label = new QLabel("mm",this);
	layout->addWidget(label);
	layout->addWidget(btn1);
	layout->addWidget(btn2);
	//��mainwindow�е����ť���Ѿ��е�widget�Ҳ����һ��widget
	//w = new QtGuiApplication1(this);//��һ��widget
	//QtGuiClassmm* v = new QtGuiClassmm(this);//�Ѿ�����д��������Խ���ʵ������
	/*QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(w);
	centralWidget()->setLayout(mainLayout);*/
	//connect(v, &QtGuiClassmm::addRightWidget1Signal, this, &QtGuiClass::addRightWidget);
	//connect(btn2, &QPushButton::clicked, this, &QtGuiClass::addRightWidget);
	//mainLayout->addWidget(v);
	
	//�ڶ��ֳ���
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
	  // ����QSplitter�ؼ�
	//QtGuiApplication1 tt;
	//QSplitter* splitter = new QSplitter(this);
	//splitter->setOrientation(Qt::Horizontal);
	//splitter->addWidget(&tt);
	//setCentralWidget(splitter);

	//// �������ؼ�
	//QTreeView* treeView = new QTreeView(splitter);
	//splitter->addWidget(treeView);

	//// �����Ҳ�ؼ�
	//QWidget* rightWidget = new QWidget(splitter);
	//QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
	////rightWidget->setLayout(rightLayout);
	//tt.setLayout(rightLayout);
	////splitter->addWidget(rightWidget);
	//splitter->addWidget(&tt);

	//// ������ť����ӵ�������
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

	//����ť2��ӷ���Ϣ������
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
	//����굱ǰλ����ʾ����
	QPoint mousepos = QCursor::pos();
	QPoint localPos = mapFromGlobal(mousepos);
	qDebug() << mousepos << "\t" << localPos;
	connect(head, &QAction::triggered, [this, localPos, menu]() {
		//menu->exec(mapToGlobal(localPos));
		menu->exec(localPos);
		});
	//��ʾ����widget.cpp����
	message = new QtGuiClassmm(this);
	search = new QtGuiApplication1(this);
	message->hide();
	/*this->setCentralWidget(search);
	this->show();*/

	//��ʾ�Ҳ�
	//�ð�ť
	
	/*QHBoxLayout* right = new QHBoxLayout(this);
	QWidget* centralWidget = new QWidget(this);
		centralWidget->setLayout(right);
		right->addWidget(search);
		setCentralWidget(search);//�������ó�ʼ��ʾ��֮�䴰��
		//search->show();
		this->show(); //��ʾ��ǰmainwindow����
		//centralWidget
	connect(btn2, &QPushButton::clicked, [=]() {//��ť���֮�������ʾ�Ļ���
		qDebug() << "2";
		message->show();
		search->show();
		right->addWidget(search);
		right->addWidget(message);
		
		
		setCentralWidget(centralWidget);
		this->show();//��ʾ��ǰmainwindow����
		//centralWidget->show();
		qDebug() << "1";
		});*/
	//������layout֮����ʾ����
	QHBoxLayout* right = new QHBoxLayout(this);
	QWidget* centralWidget = new QWidget(this);
	QFrame* line = new QFrame(this);//��������
	line->setFrameShape(QFrame::VLine);
	line->setFrameShadow(QFrame::Sunken);
	line->hide();
	centralWidget->setLayout(right);
	right->addWidget(search);
	setCentralWidget(search);//�������ó�ʼ��ʾ��֮�䴰��
	//search->show();
	this->show(); //��ʾ��ǰmainwindow����
	//centralWidget
	connect(btn2, &QPushButton::clicked, [=]() {//��ť���֮�������ʾ�Ļ���
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

		//centralWidget->setLayout(right);//�Ѳ���ӵ�֮�仭��
		setCentralWidget(centralWidget);
		this->show();//��ʾ��ǰmainwindow����
		//centralWidget->show();
		qDebug() << "1";
		});



	/*message->hide();
	
	connect(btn2, &QPushButton::clicked, [=]() {
		message->show();
		});*/
	//�ڴ������Ͻ����ؼ�
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
		//ʹ����ķ����ʽ����
		//i = new int(0);
		/*int j = 0;
		bool isWindowMaximized = this->isMaximized();
		connect(zoomInAction, &QAction::triggered, [this,zoomInAction,&j,isWindowMaximized]() {
			
			if (j % 2) {//i�������Σ���Ϊ��ʼֵΪ0��������Ӧ������
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
		//ʹ��bool������if
		bool j = false;
		bool isWindowMaximized = this->isMaximized();//��ʼ��false
		qDebug() << isWindowMaximized<<"?";
		connect(zoomInAction, &QAction::triggered, [this, zoomInAction, &j, &isWindowMaximized]() {

			if (isWindowMaximized) {//��ʼ�ǷŴ�ͼ�꣬���֮��j=true
				zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/init.png"));
				showNormal();
				qDebug() << j;
				j = false;
				isWindowMaximized = this->isMaximized();
			}
			else {//falseִ��


				zoomInAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/half.png"));
				showMaximized();
				qDebug() << j << "m";
				isWindowMaximized = true;
			}
			

			});
	zoomCloseAction->setIcon(QIcon("F:/wechat/QtGuiApplication1/QtGuiApplication1/Resources/close.png"));
		toolBartriple->addAction(zoomCloseAction);
		connect(zoomCloseAction, &QAction::triggered, this, &QtGuiClass::close);
//action����
		QWidget* spacer = new QWidget();
		spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
		toolBartriple->insertWidget(zoomOutAction, spacer);
		//addToolBar
//�滻����ԭ�еķŴ���Сͼ��
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
		//��������ͼthumbnail
//�ƶ�����
		//setWindowFlags(windowFlags() | Qt::Window);
		setMouseTracking(true);

}
//��д����ƶ�����
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
//�ڶ�����д�ƶ�����
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



//��дshowmaximized��������
//void QtGuiClass::showMaximized() {
//
//	QtGuiClass::showMaximized();
//}
void QtGuiClass::addRightWidget() {
	// v = new QtGuiClassmm(this);
		//QHBoxLayout * rightLayout = new QHBoxLayout(w);//ע������Ҫ����ȫ�ֱ����ſ���ֱ����������
		//rightLayout->addWidget(v);
}






void QtGuiClass::test() {
	qDebug() << "1";
}

QtGuiClass::~QtGuiClass()
{
}
