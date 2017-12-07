#pragma once

#include <QWidget>

class Client : public QWidget
{
	Q_OBJECT
public:
	Client(QWidget *parent = Q_NULLPTR);
	~Client();
protected:
	virtual void paintEvent(QPaintEvent *e)override;
	virtual void keyPressEvent(QKeyEvent *e)override;
protected:
	void getMsg();
protected:
	struct Data;
	Data *data;
};
