#include "keytranslator.h"
#include "frmviewkeymappings.h"
#include <QFile>
#include <QStringList>

KeyTranslator::KeyTranslator(QObject *parent) :
    QObject(parent)
{
    LookupTable.clear();
    CustomKeysFile = "resources/CustomKeys.xml";
    LoadCustomKeysFile();
}

void KeyTranslator::LoadCustomKeysFile()
{
    QDomDocument doc;
    QDomNodeList listnodes;
    QDomElement keyelement;
    bool x;
    QString errmsg;
    int errline;
    QString inkey,outkey;
    QStringList attributes;

    LookupTable.clear();
    QFile keysfile(CustomKeysFile);
    keysfile.open(QIODevice::ReadOnly);
    x = doc.setContent(keysfile.readAll(),&errmsg,&errline);
    listnodes = doc.elementsByTagName("key");

    for (int i = 0; i < listnodes.count(); i++)
    {
        KeyStroke out;
        keyelement = listnodes.at(i).toElement();
        inkey = keyelement.attribute("keyin");
        outkey = keyelement.attribute("keyout");
        attributes.clear();

        out = this->StringAsKeyStroke(outkey);
        LookupTable.insert(inkey,out);
    }
    keysfile.close();
}

void KeyTranslator::SaveCustomKeysFile()
{
    QDomDocument doc;
    QDomElement mainelement;
    QDomElement keyelement;
    QString keyoutstr;

    if (LookupTable.count() == 0)
    {
        return;
    }

    if(QFile::exists(CustomKeysFile))
        QFile::remove(CustomKeysFile);

    QFile keysfile(CustomKeysFile);
    keysfile.open(QIODevice::WriteOnly);

    mainelement = doc.createElement("Keys");
    for (int i = 0;i < LookupTable.count();i++)
    {
        keyelement = doc.createElement("key");
        keyelement.setAttribute("keyin",LookupTable.keys().at(i));
        KeyOut = LookupTable.values().at(i);
        keyoutstr = QString("%1_").arg(KeyOut.KeyCode);
        keyoutstr += (KeyOut.Ctrl ? "1_" : "0_");
        keyoutstr += (KeyOut.Alt ? "1_" : "0_");
        keyoutstr += (KeyOut.Shft ? "1" : "0");
        if (KeyOut.Custom != "")
            keyoutstr = "Custom=" + KeyOut.Custom;
        keyelement.setAttribute("keyout",keyoutstr);
        mainelement.appendChild(keyelement);
    }
    doc.appendChild(mainelement);
    keysfile.write(doc.toByteArray());
    keysfile.close();
}

int KeyTranslator::TranslateKey(int  keyin,
                                bool &ShiftPressed,
                                bool &CtrlPressed,
                                bool &AltPressed,
                                QString &CustomFunction)
{
    QString keystr = QString("%1_").arg(keyin);
    keystr += (CtrlPressed ? "1_" : "0_");
    keystr += (AltPressed ? "1_" : "0_");
    keystr += (ShiftPressed ? "1" : "0");

    if (LookupTable.contains(keystr))
    {
        ClearKeyStrokes();
        KeyOut = LookupTable.value(keystr);
        ShiftPressed = KeyOut.Shft;
        CtrlPressed = KeyOut.Ctrl;
        AltPressed = KeyOut.Alt;
        CustomFunction = KeyOut.Custom;
        return KeyOut.KeyCode;
    }
    else
    {
        ShiftPressed = ShiftPressed;
        CtrlPressed = CtrlPressed;
        AltPressed = AltPressed;
        CustomFunction = "";
        return keyin;
    }
}

void KeyTranslator::Clear()
{
   LookupTable.clear();
   ClearKeyStrokes();
}

void KeyTranslator::ClearKeyStrokes()
{
    KeyIn.KeyCode = 0;
    KeyIn.Ctrl = false;
    KeyIn.Alt = false;
    KeyIn.Shft = false;
    KeyIn.Custom = "";
    KeyOut.KeyCode = 0;
    KeyOut.Ctrl = false;
    KeyOut.Alt = false;
    KeyOut.Shft = false;
    KeyOut.Custom = "";
}

void KeyTranslator::AddKeyMapping(KeyStroke in,KeyStroke out)
{
    QString instr;
    instr = QString ("%1_").arg(in.KeyCode);
    instr += (in.Ctrl ? "1_" : "0_");
    instr += (in.Alt ? "1_" : "0_");
    instr += (in.Shft ? "1" : "0");

    LookupTable.insert(instr,out);
}

bool KeyTranslator::Contains(KeyStroke in)
{
    QString instr;
    instr = QString ("%1_").arg(in.KeyCode);
    instr += (in.Ctrl ? "1_" : "0_");
    instr += (in.Alt ? "1_" : "0_");
    instr += (in.Shft ? "1" : "0");

    return LookupTable.contains(instr);
}

QString KeyTranslator::KeyStrokeAsString(KeyStroke in)
{
    QString tmpstr = "";

    if (in.Ctrl)
    {
        tmpstr += "Ctrl ";
    }
    //
    if (in.Alt)
    {
        tmpstr += "Alt ";
    }
    if (in.Shft)
    {
        tmpstr += "Shift ";
    }

    switch (in.KeyCode)
    {
        case 0:
            tmpstr = in.Custom;
            break;
        case Qt::Key_A:
            tmpstr += "A";
            break;
        case Qt::Key_B:
            tmpstr += "B";
            break;
        case Qt::Key_C:
            tmpstr += "C";
            break;
        case Qt::Key_D:
            tmpstr += "D";
            break;
        case Qt::Key_E:
            tmpstr += "E";
            break;
        case Qt::Key_F:
            tmpstr += "F";
            break;
        case Qt::Key_G:
            tmpstr += "G";
            break;
        case Qt::Key_H:
            tmpstr += "H";
            break;
        case Qt::Key_I:
            tmpstr += "I";
            break;
        case Qt::Key_J:
            tmpstr += "J";
            break;
        case Qt::Key_K:
            tmpstr += "K";
            break;
        case Qt::Key_L:
            tmpstr += "L";
            break;
        case Qt::Key_M:
            tmpstr += "M";
            break;
        case Qt::Key_N:
            tmpstr += "N";
            break;
        case Qt::Key_O:
            tmpstr += "O";
            break;
        case Qt::Key_P:
            tmpstr += "P";
            break;
        case Qt::Key_Q:
            tmpstr += "Q";
            break;
        case Qt::Key_R:
            tmpstr += "R";
            break;
        case Qt::Key_S:
            tmpstr += "S";
            break;
        case Qt::Key_T:
            tmpstr += "T";
            break;
        case Qt::Key_U:
            tmpstr += "U";
            break;
        case Qt::Key_V:
            tmpstr += "V";
            break;
        case Qt::Key_W:
            tmpstr += "W";
            break;
        case Qt::Key_X:
            tmpstr += "X";
            break;
        case Qt::Key_Y:
            tmpstr += "Y";
            break;
        case Qt::Key_Z:
            tmpstr += "Z";
            break;
        case Qt::Key_1:
            tmpstr += "1";
            break;
        case Qt::Key_2:
            tmpstr += "2";
            break;
        case Qt::Key_3:
            tmpstr += "3";
            break;
        case Qt::Key_4:
            tmpstr += "4";
            break;
        case Qt::Key_5:
            tmpstr += "5";
            break;
        case Qt::Key_6:
            tmpstr += "6";
            break;
        case Qt::Key_7:
            tmpstr += "7";
            break;
        case Qt::Key_8:
            tmpstr += "8";
            break;
        case Qt::Key_9:
            tmpstr += "9";
            break;
        case Qt::Key_0:
            tmpstr += "0";
            break;
        case Qt::Key_F1:
            tmpstr += "F1";
            break;
        case Qt::Key_F2:
            tmpstr += "F2";
            break;
        case Qt::Key_F3:
            tmpstr += "F3";
            break;
        case Qt::Key_F4:
            tmpstr += "F4";
            break;
        case Qt::Key_F5:
            tmpstr += "F5";
            break;
        case Qt::Key_F6:
            tmpstr += "F6";
            break;
        case Qt::Key_F7:
            tmpstr += "F7";
            break;
       case Qt::Key_F8:
            tmpstr += "F8";
            break;
        case Qt::Key_F9:
            tmpstr += "F9";
            break;
        case Qt::Key_F10:
            tmpstr += "F10";
            break;
        case Qt::Key_F11:
            tmpstr += "F12";
            break;
        case Qt::Key_F12:
            tmpstr += "F12";
            break;
        case Qt::Key_Escape:
            tmpstr += "Esc";
            break;
        case Qt::Key_Print:
            tmpstr += "Prnt Scrn";
            break;
        case Qt::Key_SysReq:
            tmpstr += "SysRq";
            break;
        case Qt::Key_Pause:
            tmpstr += "Pause";
            break;
        case Qt::Key_Agrave:
            tmpstr += "`";
            break;
        case Qt::Key_AsciiTilde:
            tmpstr += "~";
            break;
        case Qt::Key_Exclam:
            tmpstr += "!";
            break;
        case Qt::Key_At:
            tmpstr += "@";
            break;
        case Qt::Key_NumberSign:
            tmpstr += "#";
            break;
        case Qt::Key_Dollar:
            tmpstr += "$";
            break;
        case Qt::Key_Percent:
            tmpstr += "%";
            break;
        case Qt::Key_AsciiCircum:
            tmpstr += "^";
            break;
        case Qt::Key_Ampersand:
            tmpstr += "&";
            break;
        case Qt::Key_Asterisk:
            tmpstr += "*";
            break;
        case Qt::Key_ParenLeft:
            tmpstr += "(";
            break;
        case Qt::Key_ParenRight:
            tmpstr += ")";
            break;
        case Qt::Key_Minus:
            tmpstr += "-";
            break;
        case Qt::Key_Underscore:
            tmpstr += "_";
            break;
        case Qt::Key_Equal:
            tmpstr += "=";
            break;
        case Qt::Key_Plus:
            tmpstr += "+";
            break;
        case Qt::Key_Backslash:
            tmpstr += "\\";
            break;
        case Qt::Key_Bar:
            tmpstr += "|";
            break;
        case Qt::Key_Backspace:
            tmpstr += "Backspace";
            break;
        case Qt::Key_Insert:
            tmpstr += "Insert";
            break;
        case Qt::Key_Delete:
            tmpstr += "Delete";
            break;
        case Qt::Key_Home:
            tmpstr += "Home";
            break;
        case Qt::Key_End:
            tmpstr += "End";
            break;
        case Qt::Key_PageUp:
            tmpstr += "Page Up";
            break;
        case Qt::Key_PageDown:
            tmpstr += "Page Down";
            break;
        case Qt::Key_Tab:
            tmpstr += "Tab";
            break;
        case Qt::Key_BracketLeft:
            tmpstr += "[";
            break;
        case Qt::Key_BraceLeft:
            tmpstr += "{";
            break;
        case Qt::Key_BracketRight:
            tmpstr += "]";
            break;
        case Qt::Key_BraceRight:
            tmpstr += "}";
            break;
        case Qt::Key_Return:
            tmpstr += "Enter";
            break;
        case Qt::Key_CapsLock:
            tmpstr += "Caps Lock";
            break;
        case Qt::Key_NumLock:
            tmpstr += "Num Lock";
            break;
        case Qt::Key_ScrollLock:
            tmpstr += "Scroll Lock";
            break;
        case Qt::Key_Semicolon:
            tmpstr += ";";
            break;
        case Qt::Key_Colon:
            tmpstr += ":";
            break;
        case Qt::Key_Apostrophe:
            tmpstr += "'";
            break;
        case Qt::Key_QuoteDbl:
            tmpstr += "\"";
            break;
        case Qt::Key_Shift:
            tmpstr += "Shift";
            break;
        case Qt::Key_Comma:
            tmpstr += ",";
            break;
        case Qt::Key_Period:
            tmpstr += ".";
            break;
        case Qt::Key_Slash:
            tmpstr += "/";
            break;
        case Qt::Key_Less:
            tmpstr += "<";
            break;
        case Qt::Key_Greater:
            tmpstr += ">";
            break;
        case Qt::Key_Question:
            tmpstr += "?";
            break;
        case Qt::Key_Control:
            tmpstr += "Ctrl";
            break;
        case Qt::Key_Alt:
            tmpstr += "Alt";
            break;
        case Qt::Key_Meta:
            tmpstr += "Win Key";
            break;
        case Qt::Key_Menu:
            tmpstr += "Menu Key";
            break;
        case Qt::Key_Left:
            tmpstr += "Left Arrow";
            break;
        case Qt::Key_Right:
            tmpstr += "Right Arrow";
            break;
        case Qt::Key_Up:
            tmpstr += "Up Arrow";
            break;
        case Qt::Key_Down:
            tmpstr += "Down Arrow";
            break;
        default:
            tmpstr = "";
        }
    return tmpstr;
}

void KeyTranslator::ViewCurrentKeyMappings()
{
    KeyStroke in;
    FrmViewKeyMappings f;
    f.Clear();

    for (int i = 0; i < LookupTable.count(); i++)
    {
        in = StringAsKeyStroke(LookupTable.keys().at(i));
        f.AddKeyMapping(KeyStrokeAsString(in) + " mapped to " + KeyStrokeAsString(LookupTable.values().at(i)));
    }
    f.Display();
}

KeyStroke KeyTranslator::StringAsKeyStroke(QString keystr)
{
    KeyStroke k;
    QStringList attributes;

    if (keystr.left(7) == "Custom=")
    {
        k.KeyCode = 0;
        k.Ctrl = false;
        k.Alt = false;
        k.Shft = false;
        k.Custom = keystr.mid(7);
    }
    else
    {
        attributes = keystr.split("_");
        k.KeyCode = attributes.at(0).toInt();
        k.Ctrl = (attributes.at(1) == "1" ? true : false);
        k.Alt = (attributes.at(2) == "1" ? true : false);
        k.Shft = (attributes.at(3) == "1" ? true : false);
        k.Custom = "";
    }
    return k;
}
