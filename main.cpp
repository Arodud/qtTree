#include <QApplication>
#include <QTreeView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* widget = new QWidget;
    widget->setWindowTitle("QTreeView");
    widget->setMinimumHeight(200);
    widget->setMinimumWidth(200);

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *parentItem = model->invisibleRootItem();
    QStandardItem *first = new QStandardItem("foo");
    QStandardItem *second = new QStandardItem("bar");

    parentItem->appendRow(first);
    parentItem->appendRow(second);

    first->appendRow(new QStandardItem("foo::test1"));
    first->appendRow(new QStandardItem("foo::test2"));

    QStandardItem *foo = new QStandardItem("tree");

    first->appendRow(foo);

    second->appendRow(new QStandardItem("bar::test1"));
    second->appendRow(new QStandardItem("bar::test2"));
    second->appendRow(new QStandardItem("bar::test3"));

    QTreeView *view = new QTreeView(widget);
    view->setModel(model);

    widget->show();
    return a.exec();
}
