#pragma once

class Command
{
public:
    enum Type : long long
    {
        OnClick = 1 << 0,
        OnHover = 1 << 1,
        OnRelease = 1 << 2,
        OnHold = 1 << 3,
    };
    Command();
    Command(long long command);

public:
    long long getId() const;
    bool isOnClicked() const;
    bool isOnHovered() const;
    bool isOnReleased() const;
    bool isOnHold() const;

    void remove(Type type);

private:
    long long m_command;
};