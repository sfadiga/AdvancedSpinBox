//!
//! MIT license
//! Fev 2020
//! by Sandro Fadiga
//!
#ifndef ADVANCEDSPINBOX_H
#define ADVANCEDSPINBOX_H

#include <QSpinBox>

//!
//! \brief The AdvancedSpinBox class
//! is a decorator over the spin box,
//! it adds a feature when a user hover over a digit
//! this digit can be incremented (individually) by using the mouse wheel
//!
class AdvancedSpinBox : public QSpinBox
{
    Q_OBJECT

    Q_PROPERTY(int digitStep READ digitStep WRITE setDigitStep)

signals:
    //!
    //! \brief digitStepChanged - is emited when digit step value is changed
    //!
    void digitStepChanged(int);

public:

    AdvancedSpinBox(QWidget*);
    ~AdvancedSpinBox() override = default;

    //!
    //! \brief digitStep - returns the current value for digit step
    //! \return
    //!
    int digitStep() const;

    //!
    //! \brief setDigitStep - sets a new value for the digit step
    //! \param val
    //!
    void setDigitStep(int val);

protected:
    //!
    //! \brief eventFilter - a filter to be installed on the lineedit and used to track hover events over the text
    //! \param e
    //! \return
    //!
    bool eventFilter(QObject *, QEvent *e) override;

private:
    //!
    //! \brief m_edit - a reference to the parent class lineedit used to shortcut references
    //!
    QLineEdit *m_edit;

    //!
    //! \brief m_digitStep - hold the value for a single digit step
    //!
    int m_digitStep;

    //!
    //! \brief BASE_10
    //!
    constexpr static int BASE_10 = 10;
};


//!
//! \brief The AdvancedDoubleSpinBox class
//! is a decorator over the double spin box,
//! it adds a feature when a user hover over a digit
//! this digit can be incremented (individually) by using the mouse wheel
//!
class AdvancedDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT

    Q_PROPERTY(int digitStep READ digitStep WRITE setDigitStep)

signals:
    //!
    //! \brief digitStepChanged - is emited when digit step value is changed
    //!
    void digitStepChanged(int);

public:

    AdvancedDoubleSpinBox(QWidget*);
    ~AdvancedDoubleSpinBox() override = default;

    //!
    //! \brief digitStep - returns the current value for digit step
    //! \return
    //!
    int digitStep() const;

    //!
    //! \brief setDigitStep - sets a new value for the digit step
    //! \param val
    //!
    void setDigitStep(int val);

protected:
    //!
    //! \brief eventFilter - a filter to be installed on the lineedit and used to track hover events over the text
    //! \param e
    //! \return
    //!
    bool eventFilter(QObject *, QEvent *e) override;

private:
    //!
    //! \brief m_edit - a reference to the parent class lineedit used to shortcut references
    //!
    QLineEdit *m_edit;

    //!
    //! \brief m_digitStep - hold the value for a single digit step
    //!
    int m_digitStep;

    //!
    //! \brief BASE_10
    //!
    constexpr static int BASE_10 = 10;

};

#endif // ADVANCEDSPINBOX_H
