#ifndef CHOICE_H
#define CHOICE_H

#include <QString>

class InteractData;

// What happens when a player selects a choice.
enum class ChoiceType {
    GET,    // Add something to inventory
    FLAG,   // Set a game flag
    TALK,   // Continue to another InteractData
    CLOSE,   // Close the interact window (default/dismiss)
    SCENE_CHANGE
};

class Choice
{
public:
    // nextData may be nullptr (e.g. for CLOSE).
    // Choice takes ownership of nextData if provided.
    explicit Choice(const QString &label,
                    ChoiceType type,
                    const QString &typeData = QString(),
                    InteractData *nextData = nullptr);
    ~Choice();

    const QString &label() const;
    ChoiceType type() const;
    const QString &typeData() const;
    InteractData *nextData() const;     // May be nullptr

private:
    QString m_label;
    ChoiceType m_type;
    QString m_typeData;
    InteractData *m_nextData;           // Owned — we delete this
};

#endif // CHOICE_H