#pragma once

class Command
{
public:
    enum Type : long long
    {
        OnClick = 1 << 0,
        OnHover = 1 << 1,
        OnHold = 1 << 2,
    };
    Command();
    Command(long long command);

public:
    long long getId() const;
    bool isOnClicked() const;
    bool isOnHovered() const;
    bool isOnHold() const;

    void remove(Type type);

private:
    long long m_command;
};