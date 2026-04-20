
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QGroupBox>
#include "profile.h"

#ifndef SIGNINFORM_H
#define SIGNINFORM_H

class SignInForm : public QWidget {
    Q_OBJECT
    
public:
    explicit SignInForm(QWidget *parent = nullptr);
    QMap<QString, Profile> users;
    
private:
    QLabel *firstNameLabel;
    QLineEdit *firstNameEdit;
    
    QLabel *lastNameLabel;
    QLineEdit *lastNameEdit;
    
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    
    QLabel *passwordLabel;
    QLineEdit * passwordEdit;
    
    QPushButton *refreshButton;
    QPushButton *finishButton;
    
    QLabel *genderLabel;
    QGroupBox *genderBox;
    QRadioButton *genderMale;
    QRadioButton *genderFemale;
    
    QSpinBox *birthday_daySlider;
    QSpinBox *birthday_monthSlider;
    QSpinBox *birthday_yearSlider;
    
    QPushButton *uploadButton;
    QLabel *imagePreview;
    QString imagePath;
    
    
private slots:
    void fillSummary();
    void clearStuff();
    bool validatePassword(const QString &password);
    void pickProfileImage();
    
    
signals:
};

#endif // MAINWIDGET_H
