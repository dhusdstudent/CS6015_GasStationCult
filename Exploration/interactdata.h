#ifndef INTERACTDATA_H
#define INTERACTDATA_H

#include <QString>
#include <QList>

// Forward declared so Choice can reference it without circular include
class Choice;

class InteractData
{
public:
    explicit InteractData(const QString &text, QObject *owner = nullptr);
    ~InteractData();

    void addChoice(Choice *choice);      // Takes ownership
    const QString &text() const;
    const QList<Choice*> &choices() const;

private:
    QString m_text;
    QList<Choice*> m_choices;            // Composed — we own and delete these
};

#endif // INTERACTDATA_H