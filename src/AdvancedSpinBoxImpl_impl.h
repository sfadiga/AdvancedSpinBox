#pragma once

#include <QAdvancedSpinBox/AdvancedSpinBoxImpl.h>

#include <QMouseEvent>
#include <QLineEdit>
#include <cmath>

template <typename SpinBoxT> AdvancedSpinBoxImpl<SpinBoxT>::AdvancedSpinBoxImpl(QWidget *w)
	: SpinBoxT(w), AdvancedSpinBoxBase(), m_digitStep(1)
{
	m_edit = this->lineEdit();
	m_edit->installEventFilter(static_cast<SpinBoxT*>(this));

	//have to, slots and signals are incompatible to multiple inheritance and Qt doesn't support connecting just methods other than slots
	// and we cannot use slots, because MOC-generated code conflicts with inheritance and templates we use, and we surely shouldn't modify MOC, it's Qt devs job
	this->connect(m_edit, &std::remove_pointer<decltype(m_edit)>::type::cursorPositionChanged,
		this,
		[&](int oldPos, int newPos) {
			this->cursorPositionChangedProcessor(oldPos, newPos);
		}
	);
}

template <typename SpinBoxT> typename AdvancedSpinBoxImpl<SpinBoxT>::ValueT AdvancedSpinBoxImpl<SpinBoxT>::digitStep()
{
	return m_digitStep;
}

template <typename SpinBoxT> void AdvancedSpinBoxImpl<SpinBoxT>::setDigitStep(AdvancedSpinBoxImpl<SpinBoxT>::ValueT val)
{
	m_digitStep = val;
	//Q_EMIT digitStepChanged(val);
}

template <typename SpinBoxT> void AdvancedSpinBoxImpl<SpinBoxT>::updateStep(int length)
{
	auto pow = this->pos2Pow(length);
	auto step = static_cast<ValueT>(m_digitStep * std::pow(this->displayIntegerBase(), pow));
	this->setSingleStep(step);
}

template <typename SpinBoxT> int AdvancedSpinBoxImpl<SpinBoxT>::displayIntegerBase(){
	return SpinBoxT::displayIntegerBase();
}

template <typename SpinBoxT> int AdvancedSpinBoxImpl<SpinBoxT>::decimals(){
	return SpinBoxT::decimals();
}

template <typename SpinBoxT> bool AdvancedSpinBoxImpl<SpinBoxT>::isNegative(){
	return SpinBoxT::value() < 0;
}

template <typename SpinBoxT> bool AdvancedSpinBoxImpl<SpinBoxT>::eventFilter(QObject *o, QEvent *e){
	return AdvancedSpinBoxBase::eventFilter(o, e);
}

template <typename SpinBoxT> void AdvancedSpinBoxImpl<SpinBoxT>::stepBy(int steps){
	SpinBoxT::stepBy(steps);
	m_edit->setCursorPosition(rawCursorIndex);
}

template <typename SpinBoxT> void AdvancedSpinBoxImpl<SpinBoxT>::setSuffix(const QString &suffix){
	SpinBoxT::setSuffix(suffix);
	suffixLength = this->suffix().length();
	//Q_EMIT suffixChanged(suffix);
};

template <typename SpinBoxT> void AdvancedSpinBoxImpl<SpinBoxT>::setPrefix(const QString &prefix){
	SpinBoxT::setPrefix(prefix);
	prefixLength = this->prefix().length();
	//Q_EMIT prefixChanged(prefix);
};
