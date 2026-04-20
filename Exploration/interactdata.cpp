#include "interactdata.h"
#include "choice.h"

InteractData::InteractData(const QString &text, QObject *owner)
    : m_text(text)
{
    Q_UNUSED(owner);
}

InteractData::~InteractData()
{
    qDeleteAll(m_choices);
}

void InteractData::addChoice(Choice *choice)
{
    m_choices.append(choice);
}

const QString &InteractData::text() const
{
    return m_text;
}

const QList<Choice*> &InteractData::choices() const
{
    return m_choices;
}