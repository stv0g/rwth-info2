#include "testprogramm.h"
#include <QWebView>
#include <QDir>
#include <QUrl>

/*!\brief Wenn Sie das lesen koennen, ist Doxygen funktionsfaehig
 *\param parent Der Parent des Objektes
 */
testProgramm::testProgramm(QWidget *parent)
    : QMainWindow(parent)
{
	QWebView *view = new QWebView(this);

	QDir dir("html");
	QUrl url();
	
  	//view->setSource(QUrl::fromLocalFile(dir.absoluteFilePath("classtest_programm.html")));
	//in der neuesten Version 4.7.0 wird view->setSource durch view->setUrl ersetzt.
	view->setUrl(QUrl::fromLocalFile(dir.absoluteFilePath("classtest_programm.html")));
	this->setCentralWidget(view);

}

testProgramm::~testProgramm()
{

}
