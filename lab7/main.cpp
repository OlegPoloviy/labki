#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout); // ініціалізуємо QTextStream зі стандартним виведенням (stdout)
    out << "Hello, world!" << endl; // виводимо текст у консоль

    return a.exec();
}
