#pragma once
//!
//! MIT license
//! Fev 2020
//! by Sandro Fadiga
//!
#ifndef ADVANCEDSPINBOXBASE_H
#define ADVANCEDSPINBOXBASE_H

#include <QObject>
#include <QEvent>
#include <QLineEdit>

#include "api.h"

class QAdvancedSpinBox_API ISpinBoxWithDisplayIntegerBaseAndDecimals{
	//Q_OBJECT
public:
	virtual int displayIntegerBase() = 0;
	virtual int decimals() = 0;
	virtual bool isNegative() = 0;

	void suffixChanged(const QString&);
	void prefixChanged(const QString&);
};

class QAdvancedSpinBox_API AdvancedSpinBoxBase: public ISpinBoxWithDisplayIntegerBaseAndDecimals
{
	//Q_OBJECT
protected:
	//!
	//! \brief eventFilter - a filter to be installed on the lineedit and used to track hover events over the text
	//! \param e
	//! \return
	//!
	bool eventFilter(QObject *, QEvent *e);

	//!
	//! \brief m_edit - a reference to the parent class lineedit used to shortcut references
	//!
	QLineEdit *m_edit = nullptr;

	int cursorIndex = 0;
	int rawCursorIndex = 0;

protected:
	decltype(static_cast<QString*>(nullptr)->length()) prefixLength=0, suffixLength=0;

public:

	AdvancedSpinBoxBase();
	~AdvancedSpinBoxBase() = default;

	int pos2Pow(int length);

	virtual void updateStep(int length) = 0;


	void cursorPositionChangedProcessor(int oldPos, int newPos);
};

#endif // ADVANCEDSPINBOXBASE_H
