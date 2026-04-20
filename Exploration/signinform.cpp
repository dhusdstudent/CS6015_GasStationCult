#include "signinform.h"
#include "profile.h"
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QGroupBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFileDialog>

SignInForm::SignInForm(QWidget *parent) : QWidget{parent} {

    //---------------------------INITIALIZATION------------------------
    usernameLabel = new QLabel("Username:");
    usernameEdit = new QLineEdit();
    usernameEdit->setFixedWidth(100);

    passwordLabel = new QLabel("Password:");
    passwordEdit = new QLineEdit();
    passwordEdit->setFixedWidth(100);

    firstNameLabel = new QLabel("First Name:");
    firstNameEdit = new QLineEdit();
    firstNameEdit->setFixedWidth(100);

    lastNameLabel = new QLabel("Last Name:");
    lastNameEdit = new QLineEdit();
    lastNameEdit->setFixedWidth(100);

    finishButton = new QPushButton("Clear Form");
    finishButton->setFixedWidth(100);

    refreshButton = new QPushButton("Submit Form");

    genderLabel = new QLabel("Gender:");
    genderBox = new QGroupBox("Gender:");
    genderMale = new QRadioButton("Male");
    genderFemale = new QRadioButton("Female");

    //---------------------------Birthday------------------------
    birthday_daySlider = new QSpinBox();
    birthday_daySlider->setRange(1, 31);

    birthday_monthSlider = new QSpinBox();
    birthday_monthSlider->setRange(1, 12);

    birthday_yearSlider = new QSpinBox();
    birthday_yearSlider->setRange(1970, 2026);
    birthday_yearSlider->setValue(2000);

    //------------------------Gender------------------------
    QVBoxLayout *genderLayout = new QVBoxLayout();
    genderLayout-> addWidget(genderMale);
    genderLayout->addWidget(genderFemale);
    genderBox-> setLayout(genderLayout);

    //---------------------------MY LAYOUT------------------------
    QGridLayout *gridLayout = new QGridLayout();

    gridLayout->addWidget(usernameLabel, 0, 0);
    gridLayout->addWidget(usernameEdit, 0, 1);

    gridLayout->addWidget(passwordLabel, 1, 0);
    gridLayout->addWidget(passwordEdit, 1, 1);

    gridLayout->addWidget(firstNameLabel, 2, 3);
    gridLayout->addWidget(firstNameEdit, 2, 4);

    gridLayout->addWidget(lastNameLabel, 3, 3);
    gridLayout->addWidget(lastNameEdit, 3, 4);

    gridLayout ->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, 2);
    gridLayout->addWidget(new QLabel("Birthday:"), 0, 3);
    gridLayout->addWidget(birthday_monthSlider, 0, 4);
    gridLayout->addWidget(birthday_daySlider, 0, 5);
    gridLayout->addWidget(birthday_yearSlider, 0, 6);

    //------------------------Buttons------------------------
    gridLayout->addWidget(genderBox, 3, 0, 2, 2);
    gridLayout->addWidget(refreshButton, 8, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(finishButton);

    uploadButton = new QPushButton("Upload Profile Image");
    imagePreview = new QLabel();
    imagePreview ->setFixedSize(100, 100);
    imagePreview->setStyleSheet("border: 1px solid black;");
    imagePreview->setScaledContents(true);

    gridLayout->addWidget(uploadButton, 4, 3);
    gridLayout->addWidget(imagePreview, 4, 4);

    setLayout(mainLayout);

    //------------------------Functions------------------------
    connect(refreshButton, &QPushButton::clicked, this,
            &SignInForm::fillSummary);

    connect(finishButton, &QPushButton::clicked, this,
            &SignInForm::clearStuff);

    connect(uploadButton, &QPushButton::clicked, this,
            &SignInForm::pickProfileImage);
}

bool SignInForm::validatePassword(const QString &password){
    if (password.length() < 8) return false;

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for (QChar c : password){
        if (c.isUpper()) hasUpperCase = true;
        if (c.isLower()) hasLowerCase = true;
        if (c.isDigit()) hasDigit = true;
    }
    return hasUpperCase && hasLowerCase && hasDigit;
}

void SignInForm::pickProfileImage(){
    QString file = QFileDialog::getOpenFileName(this, "Select Profile Image",
                                                "", "Images (*.png *.jpg *.jpeg *.bmp");

    if (file.isEmpty()) return;

    imagePath = file;
    QPixmap pixmap(file);
    imagePreview->setPixmap(pixmap);
}

void SignInForm::fillSummary() {
    Profile newUser;

    newUser.password = passwordEdit->text();
    if (!validatePassword(newUser.password)) {
        passwordEdit->setText("Your password has not met the requirements!");
        return;
    }

    newUser.username = usernameEdit->text();
    if (users.contains(newUser.username)) {
        usernameEdit->setText("That username is already in use.");
        return;
    }

    newUser.firstName = firstNameEdit->text();
    newUser.lastName = lastNameEdit->text();
    newUser.profileImagePath = imagePath;

    newUser.birthday_day = QString::number(birthday_daySlider->value());
    newUser.birthday_month = QString::number(birthday_monthSlider->value());
    newUser.birthday_year = QString::number(birthday_yearSlider->value());

    if (genderMale->isChecked()){
        newUser.gender = "Male";
    } else if (genderFemale->isChecked()){
        newUser.gender = "Female";
    }

    users.insert(newUser.username, newUser);

}

void SignInForm::clearStuff() {
    //Clears the text
    firstNameEdit->clear();
    lastNameEdit->clear();
    birthday_daySlider->setValue(1);
    birthday_monthSlider->setValue(1);
    birthday_yearSlider->setValue(2000);
    passwordEdit->clear();
    usernameEdit->clear();


    //Unchecks the boxes
    genderMale->setAutoExclusive(false);
    genderMale->setChecked(false);
    genderMale->setAutoExclusive(true);

    genderFemale->setAutoExclusive(false);
    genderFemale->setChecked(false);
    genderFemale->setAutoExclusive(true);

}
