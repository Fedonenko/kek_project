#pragma once

#include <QPushButton>

class escape_button
	: public QPushButton
{
	Q_OBJECT

public:
	escape_button(QWidget* parent = nullptr);
	virtual ~escape_button();

protected:
	virtual bool event(QEvent* event) override;

	void escape();
};

