#ifndef KEYTRANSLATOR_H
#define KEYTRANSLATOR_H

#include <QObject>
#include <QDomDocument>
#include <QDomElement>
#include <QHash>

struct KeyStroke
{
    int KeyCode;
    bool Ctrl;
    bool Alt;
    bool Shft;
    QString Custom;
};

class KeyTranslator : public QObject
{
Q_OBJECT

private:
    void LoadCustomKeysFile();
    void ClearKeyStrokes();

    KeyStroke StringAsKeyStroke(QString keystr);

    QString CustomKeysFile;
    QHash <QString,KeyStroke> LookupTable;
    KeyStroke KeyIn, KeyOut;

public:
    explicit KeyTranslator(QObject *parent = 0);

    int TranslateKey(int keyin,
                     bool &ShiftPressed,
                     bool &CtrlPressed,
                     bool &AltPressed,
                     QString &CustomFunction);
    void AddKeyMapping(KeyStroke in, KeyStroke out);
    bool Contains(KeyStroke in);
    void Clear();
    void SaveCustomKeysFile();
    void ViewCurrentKeyMappings();
    QString KeyStrokeAsString(KeyStroke in);
};

#endif // KEYTRANSLATOR_H
