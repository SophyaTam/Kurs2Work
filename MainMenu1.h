#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> // ��� std::unique_ptr
class Option {
public:
    virtual std::string GetName() const = 0; // ����������� ����� ��� ��������� ����� �����
    virtual ~Option() = default; // ����������� ����������
};

class ChildOption : public Option {
public:
    std::string GetName() const override { return "�������"; }
};

class DetectiveOption : public Option {
public:
    std::string GetName() const override { return "���������"; }
};

class ComedyOption : public Option {
public:
    std::string GetName() const override { return "�������"; }
};

class MelodramaOption : public Option {
public:
    std::string GetName() const override { return "���������"; }
};

class SeriesOption : public Option {
public:
    std::string GetName() const override { return "�������"; }
};

class MainMenu1 {
private:
    std::vector<std::unique_ptr<Option>> AvailableOptions; // ������ ���������� ���������� �� �����
public:
    void AddOptions();
    std::string AddOptionsInput(int n);
    std::string WelcomeText();
};