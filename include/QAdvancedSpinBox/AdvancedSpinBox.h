#pragma once
//!
//! MIT license
//! Fev 2020
//! by Sandro Fadiga
//!
#ifndef ADVANCEDSPINBOX_H
#define ADVANCEDSPINBOX_H

#include <QSpinBox>
#include "api.h"
#include "AdvancedSpinBoxImpl.h"

class QSpinBoxWithDecimals: public QSpinBox, public ISpinBoxWithDisplayIntegerBaseAndDecimals{
	//Q_OBJECT
public:
	QSpinBoxWithDecimals(QWidget*);
	virtual ~QSpinBoxWithDecimals() override = default;

	virtual int displayIntegerBase() override;

	virtual int decimals() override {
		return 0;
	}

	void installEventFilter(QObject *o){
		QSpinBox::installEventFilter(o);
	}
};

using AdvancedSpinBox = AdvancedSpinBoxImpl<QSpinBoxWithDecimals>;

#endif // ADVANCEDSPINBOX_H
