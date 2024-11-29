#include "registerform.h"
#include "registerform.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>

RegisterForm::RegisterForm(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("Регистрация", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(titleLabel);

    QLabel *emailLabel = new QLabel("E-mail или номер телефона", this);
    emailLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(emailLabel);

    emailInput = new QLineEdit(this);
    emailInput->setStyleSheet("border: 1px solid #ccc; border-radius: 5px; padding: 5px;");
    layout->addWidget(emailInput);

    QLabel *usernameLabel = new QLabel("Имя пользователя", this);
    usernameLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(usernameLabel);

    usernameInput = new QLineEdit(this);
    usernameInput->setStyleSheet("border: 1px solid #ccc; border-radius: 5px; padding: 5px;");
    layout->addWidget(usernameInput);

    QLabel *passwordLabel = new QLabel("Пароль", this);
    passwordLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(passwordLabel);

    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordInput->setStyleSheet("border: 1px solid #ccc; border-radius: 5px; padding: 5px;");
    layout->addWidget(passwordInput);

    QLabel *confirmPasswordLabel = new QLabel("Повторите пароль", this);
    confirmPasswordLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(confirmPasswordLabel);

    confirmPasswordInput = new QLineEdit(this);
    confirmPasswordInput->setEchoMode(QLineEdit::Password);
    confirmPasswordInput->setStyleSheet("border: 1px solid #ccc; border-radius: 5px; padding: 5px;");
    layout->addWidget(confirmPasswordInput);

    QLabel *genderLabel = new QLabel("Укажите Ваш пол", this);
    genderLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(genderLabel);

    QHBoxLayout *genderLayout = new QHBoxLayout();
    maleRadio = new QRadioButton("Мужской", this);
    femaleRadio = new QRadioButton("Женский", this);
    genderLayout->addWidget(maleRadio);
    genderLayout->addWidget(femaleRadio);
    layout->addLayout(genderLayout);

    QLabel *ageLabel = new QLabel("Возраст", this);
    ageLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(ageLabel);

    ageInput = new QLineEdit(this);
    ageInput->setStyleSheet("border: 1px solid #ccc; border-radius: 5px; padding: 5px;");
    layout->addWidget(ageInput);

    QLabel *preferenceLabel = new QLabel("Предпочтение в собеседнике", this);
    preferenceLabel->setStyleSheet("font-size: 16px;");
    layout->addWidget(preferenceLabel);

    QHBoxLayout *preferenceLayout = new QHBoxLayout();
    QLabel *genderPrefLabel = new QLabel("Пол:", this);
    genderPrefCombo = new QComboBox(this);
    genderPrefCombo->addItem("Мужской");
    genderPrefCombo->addItem("Женский");
    genderPrefCombo->addItem("Любой");
    preferenceLayout->addWidget(genderPrefLabel);
    preferenceLayout->addWidget(genderPrefCombo);

    QLabel *agePrefLabel = new QLabel("Возраст:", this);
    agePrefCombo = new QComboBox(this);
    agePrefCombo->addItem("16-18");
    agePrefCombo->addItem("18-21");
    agePrefCombo->addItem("21-25");
    agePrefCombo->addItem("25+");
    preferenceLayout->addWidget(agePrefLabel);
    preferenceLayout->addWidget(agePrefCombo);

    layout->addLayout(preferenceLayout);

    registerButton = new QPushButton("Зарегистрироваться", this);
    registerButton->setStyleSheet("background-color: #28A745; color: white; border: none; border-radius: 5px; padding: 10px;");
    layout->addWidget(registerButton);

    loginButton = new QPushButton("Вход", this);
    loginButton->setStyleSheet("background-color: #6C757D; color: white; border: none; border-radius: 5px; padding: 10px;");
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &RegisterForm::loginClicked);
    connect(registerButton, &QPushButton::clicked, this, &RegisterForm::onRegisterClicked);
}

void RegisterForm::onRegisterClicked() {
    QMessageBox::information(this, "Успешная регистрация", "Вы успешно зарегистрировались!");
}
