#include <Command.hpp>

Command::Command()
: m_command(-1)
{
}

Command::Command(long long command)
: m_command(command)
{
}

long long Command::getId() const
{
    return m_command;
}

bool Command::isOnClicked() const
{
    return m_command & OnClick;
}

bool Command::isOnHovered() const
{
    return m_command & OnHover;
}

bool Command::isOnHold() const
{
    return m_command & OnHold;
}

void Command::remove(Type type)
{
    m_command &= ~type;
}