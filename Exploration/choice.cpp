#include "choice.h"
#include "interactdata.h"

Choice::Choice(const QString &label,
               ChoiceType type,
               const QString &typeData,
               InteractData *nextData)
    : m_label(label)
    , m_type(type)
    , m_typeData(typeData)
    , m_nextData(nextData)
{
}

Choice::~Choice()
{
    delete m_nextData;
}

const QString &Choice::label() const { return m_label; }
ChoiceType Choice::type() const { return m_type; }
const QString &Choice::typeData() const { return m_typeData; }
InteractData *Choice::nextData() const { return m_nextData; }