#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> // Для std::unique_ptr
class Option {
public:
    virtual std::string GetName() const = 0; // Виртуальный метод для получения имени опции
    virtual ~Option() = default; // Виртуальный деструктор
};

class ChildOption : public Option {
public:
    std::string GetName() const override { return "Детское"; }
};

class DetectiveOption : public Option {
public:
    std::string GetName() const override { return "Детестивы"; }
};

class ComedyOption : public Option {
public:
    std::string GetName() const override { return "Комедии"; }
};

class MelodramaOption : public Option {
public:
    std::string GetName() const override { return "Мелодрамы"; }
};

class SeriesOption : public Option {
public:
    std::string GetName() const override { return "Сериалы"; }
};

class MainMenu1 {
private:
    std::vector<std::unique_ptr<Option>> AvailableOptions; // Вектор уникальных указателей на опции
public:
    void AddOptions();
    std::string AddOptionsInput(int n);
    std::string WelcomeText();
};