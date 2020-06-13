#pragma once
//!
//! MIT license
//! Fev 2020
//! by Sandro Fadiga
//!
#ifndef ADVANCEDSPINBOXIMPL_H
#define ADVANCEDSPINBOXIMPL_H

#include <QAbstractSpinBox>
#include "api.h"
#include "AdvancedSpinBoxBase.h"


//!
//! \brief The AdvancedSpinBox class
//! is a decorator over the spin box,
//! it adds a feature when a user hover over a digit
//! this digit can be incremented (individually) by using the mouse wheel
//!
template <typename SpinBoxT> class QAdvancedSpinBox_API AdvancedSpinBoxImpl : public SpinBoxT, public AdvancedSpinBoxBase
{
	//Q_OBJECT
public:
	using ValueT = decltype(reinterpret_cast<SpinBoxT*>(NULL)->value());
	//Q_PROPERTY(ValueT digitStep READ digitStep WRITE setDigitStep)

	//!
	//! \brief digitStepChanged - is emited when digit step value is changed
	//!
	//Q_SIGNAL void digitStepChanged(ValueT);

protected:
	//!
	//! \brief m_digitStep - hold the value for a single digit step
	//!
	ValueT m_digitStep;

	//!
	//! \brief eventFilter - a filter to be installed on the lineedit and used to track hover events over the text
	//! \param e
	//! \return
	//!
	bool eventFilter(QObject *, QEvent *e) override;
	void stepBy(int steps) override;

public:

	AdvancedSpinBoxImpl(QWidget*);
	virtual ~AdvancedSpinBoxImpl() override = default;

	//!
	//! \brief digitStep - returns the current value for digit step
	//! \return
	//!
	ValueT digitStep();

	//!
	//! \brief setDigitStep - sets a new value for the digit step
	//! \param val
	//!
	void setDigitStep(ValueT val);

	virtual void updateStep(int length) override;

	virtual int displayIntegerBase() override;

	virtual int decimals() override;

	bool isNegative() override;

	void setSuffix(const QString &suffix);
	void setPrefix(const QString &prefix);
};

#endif // ADVANCEDSPINBOXIMPL_H
