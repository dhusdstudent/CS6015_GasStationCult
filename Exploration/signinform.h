#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QGroupBox>

class SignInForm: public QWidget {
    Q_OBJECT

public:
    explicit SignInForm(QWidget *parent = nullptr);

private:
    QLabel *firstNameLabel;
    QLineEdit *firstNameEdit;

    QLabel *lastNameLabel;
    QLineEdit *lastNameEdit;

    QPushButton *refreshButton;
    QPushButton *finishButton;

    QTextEdit *summaryText;

    QLabel *genderLabel;
    QGroupBox *genderBox;
    QRadioButton *genderMale;
    QRadioButton *genderFemale;

    QSpinBox *ageSlider;


private slots:
    void fillSummary();
    void clearStuff();


signals:
};

#endif // SIGNINFORM_H
