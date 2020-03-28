#pragma once
//!
//! MIT license
//! Fev 2020
//! by Sandro Fadiga
//!
#ifndef ADVANCEDDOUBLESPINBOX_H
#define ADVANCEDDOUBLESPINBOX_H

#include <QDoubleSpinBox>
#include "api.h"
#include "AdvancedSpinBoxImpl.h"

class QDoubleSpinBoxWithDisplayIntegerBase: public QDoubleSpinBox, public ISpinBoxWithDisplayIntegerBaseAndDecimals{
	//Q_OBJECT

public:
	//!
	//! \brief BASE_10
	//!
	static const int BASE = 10;

	QDoubleSpinBoxWithDisplayIntegerBase(QWidget*);
	virtual ~QDoubleSpinBoxWithDisplayIntegerBase() override = default;

	virtual int displayIntegerBase() override {
		return BASE;
	}

	void installEventFilter(QObject *o){
		QDoubleSpinBox::installEventFilter(o);
	}

	virtual int decimals() override;
};

using AdvancedDoubleSpinBox = AdvancedSpinBoxImpl<QDoubleSpinBoxWithDisplayIntegerBase>;

#endif // ADVANCEDDOUBLESPINBOX_H
